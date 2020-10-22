#include "../includes/minishell.h"

void	exec_cmd_path_env(char *cmd)
{
	int			idx;
	char		**path_list;
	char		*temp_value;

	idx = -1;
	while (g_env_list[++idx].key)
		if (ft_strncmp(g_env_list[idx].key, "PATH", 4) == 0 && g_env_list[idx].key[4] == 0)
			break ;
	temp_value = find_value(g_env_list[idx].key);
	if (!(path_list = ft_split(temp_value, ':')))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		set_exit_status(1);
		return ;	
	}



	struct stat	file_info;
	int			flag;
	char		*temp;
	char		*temp2;

	flag = 1;
	idx = -1;
	while (path_list[++idx])
	{
		temp = ft_strjoin(path_list[idx], "/");
		temp2 = ft_strjoin(temp, cmd);
		free(temp);
		if (lstat(temp2, &file_info) == -1)
		{
			flag = 1;
			free(temp2);
			continue ;
		}
		free(temp2);
		if ((file_info.st_mode & S_IFDIR) != 0)
		{
			flag = 2;
			continue ;
		}
		if ((file_info.st_mode & S_IXUSR) == 0)
		{
			flag = 3;
			continue ;
		}
		else
		{
			flag = 0;
			break ;
		}
	}
	free_double_pointer(path_list);
	if (flag == 0)
	{
		ft_putstr("hello world\n");
	}
	else if (flag == 1)
	{
		ft_putstr_fd("error: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": No such file or directory.\n", 2);
		set_exit_status(127);
		return ;
	}
	else if (flag == 2)
	{
		ft_putstr_fd("error: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": is a directory.\n", 2);
		set_exit_status(126);
		return ;
	}
	else if (flag == 3)
	{
		ft_putstr_fd("error: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Permission denied.\n", 2);
		set_exit_status(126);
		return ;
	}
}
