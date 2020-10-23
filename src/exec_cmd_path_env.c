#include "../includes/minishell.h"

char		**parse_path_list(void)
{
	int		idx;
	char	*temp_value;
	char	**result;

	idx = -1;
	while (g_env_list[++idx].key)
		if (ft_strncmp(g_env_list[idx].key, "PATH", 4) == 0
			&& g_env_list[idx].key[4] == 0)
			break ;
	temp_value = find_value(g_env_list[idx].key);
	if (!(result = ft_split(temp_value, ':')))
		return (NULL);
	return (result);
}

int			get_cmd_run_flag(char *cmd, char **full_cmd)
{
	struct stat	file_info;

	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (lstat(cmd, &file_info) == -1)
			return (1);
		if ((file_info.st_mode & S_IFDIR) != 0)
			return (2);
		if ((file_info.st_mode & S_IXUSR) == 0)
			return (3);
		else
		{
			*full_cmd = ft_strdup(cmd);
			return (0);
		}
	}
	return (-1);
}

char		*add_path_to_cmd(char *path, char *cmd)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(path, "/");
	result = ft_strjoin(temp, cmd);
	free(temp);
	return (result);
}

int			get_cmd_run_flag_with_path(char *cmd, char **path_list,
										char **full_cmd)
{
	int			idx;
	int			flag;
	struct stat	file_info;

	idx = -1;
	flag = -1;
	while (path_list[++idx])
	{
		*full_cmd = add_path_to_cmd(path_list[idx], cmd);
		if (lstat(*full_cmd, &file_info) == -1)
		{
			flag = 1;
			free(*full_cmd);
			continue ;
		}
		if ((file_info.st_mode & S_IFDIR) != 0)
			return (2);
		if ((file_info.st_mode & S_IXUSR) == 0)
			return (3);
		else
			return (0);
	}
	return (flag);
}

static void	print_error_msg(char *cmd, char *msg, int exit_status,
							char **full_cmd)
{
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(".\n", 2);
	set_exit_status(exit_status);
	if (full_cmd != NULL)
		free(*full_cmd);
}

void		sig_execve_handler(int signo)
{
	if (signo == SIGINT)
		ft_putstr("\b\bSIGINT\n");
	else if (signo == SIGQUIT)
		ft_putstr("\b\bSIGQUIT\n");
}

void		run_another_program(char **full_cmd)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = fork();
	signal(SIGINT, (void *)sig_execve_handler);
	signal(SIGQUIT, (void *)sig_execve_handler);
	if (pid == 0)
	{
		char	*exe_argv[] = {*full_cmd, NULL};
		execve(*full_cmd, exe_argv, g_envp);
	}
	else if (pid > 0)
	{
		ret = waitpid(pid, &status, WUNTRACED);
		set_exit_status(0);
	}
	else
	{
		ft_putstr_fd("error: fork fails.\n", 2);
		set_exit_status(1);
	}
	free(*full_cmd);
}

void		exec_cmd_path_env(char *cmd)
{
	int		flag;
	char	**path_list;
	char	*full_cmd;

	if (!(path_list = parse_path_list()))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		set_exit_status(1);
		return ;
	}
	full_cmd = NULL;
	flag = get_cmd_run_flag(cmd, &full_cmd);
	if (flag == -1)
		flag = get_cmd_run_flag_with_path(cmd, path_list, &full_cmd);
	free_double_pointer(path_list);
	if (flag == 0)
		run_another_program(&full_cmd);
	else if (flag == 1)
		print_error_msg(cmd, "command not found", 127, NULL);
	else if (flag == 2)
		print_error_msg(cmd, "is a directory", 126, &full_cmd);
	else if (flag == 3)
		print_error_msg(cmd, "Permission denied", 126, &full_cmd);
}
