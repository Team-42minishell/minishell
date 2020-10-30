#include "../includes/minishell.h"

char		**parse_path_list(void)
{
	int		idx;
	char	*temp_value;
	char	**result;

	idx = -1;
	/*
	while (g_env_list[++idx].key)
		if (ft_strncmp(g_env_list[idx].key, "PATH", 4) == 0
			&& g_env_list[idx].key[4] == 0)
			break ;
	temp_value = find_value(g_env_list[idx].key);
	*/
	temp_value = find_value("PATH");
	/*
	if (!(result = ft_split(temp_value, ':')))
		return (NULL);
		*/
	result = ft_split(temp_value, ':');
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
	set_res(exit_status);
	if (full_cmd != NULL)
		free(*full_cmd);
}

void		set_exe_argv(char *full_cmd, char **arg_list, char ***exe_argv)
{
	char	**result;
	int		len;
	int		idx;

	len = ft_len_doublestr(arg_list) + 1;
	result = (char **)ft_calloc(sizeof(char *), (len + 1));
	result[0] = ft_strdup(full_cmd);
	idx = 0;
	while (++idx < len)
		result[idx] = ft_strdup(arg_list[idx - 1]);
	*exe_argv = result;
}

void		run_another_program(char **full_cmd, t_command *cmd)
{
	pid_t	pid;
	char	**exe_argv;

	pid = fork();
	signal(SIGINT, (void *)sig_execve_handler);
	signal(SIGQUIT, (void *)sig_execve_handler);
	if (pid == 0)
	{
		if (cmd->idx != 0)
			close(g_pipes[cmd->idx * 2 - 1]);
		set_exe_argv(*full_cmd, cmd->arg_list, &exe_argv);
		execve(*full_cmd, exe_argv, g_envp);
		ft_free_doublestr(&exe_argv);
	}
	else if (pid < 0)
	{
		ft_putstr_fd("error: fork fails.\n", 2);
		set_res(1);
	}
	if (cmd->idx != 0)
		close(g_pipes[cmd->idx * 2 - 1]);
	free(*full_cmd);
}

void		cmd_execve(t_command *cmd)
{
	int		flag;
	char	**path_list;
	char	*full_cmd;

	if (!(path_list = parse_path_list()))
	{
		print_error_msg(cmd->cmd, "command not found", 127, NULL);
		return ;
	}
	full_cmd = NULL;
	flag = get_cmd_run_flag(cmd->cmd, &full_cmd);
	if (flag == -1)
		flag = get_cmd_run_flag_with_path(cmd->cmd, path_list, &full_cmd);
	free_double_pointer(path_list);
	if (flag == 0)
		run_another_program(&full_cmd, cmd);
	else if (flag == 1)
		print_error_msg(cmd->cmd, "command not found", 127, NULL);
	else if (flag == 2)
		print_error_msg(cmd->cmd, "is a directory", 126, &full_cmd);
	else if (flag == 3)
		print_error_msg(cmd->cmd, "Permission denied", 126, &full_cmd);
}
