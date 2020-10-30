/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:10:20 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 22:10:21 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**parse_path_list(void)
{
	int		idx;
	char	*temp_value;
	char	**result;

	idx = -1;
	temp_value = find_value("PATH");
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
