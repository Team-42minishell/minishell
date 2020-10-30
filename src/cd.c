/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:40:10 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 21:51:13 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_pwd_and_res(char *path)
{
	set_env("PWD", path);
	set_res(0);
	ft_free_str(&path);
	return ;
}

void	cmd_cd(t_command *command)
{
	char	*home_path;
	int		argc;

	argc = ft_len_doublestr(command->arg_list);
	if (argc == 0)
	{
		home_path = ft_strdup(find_value("HOME"));
		if (chdir(home_path) == -1)
			return (error_builtin("cd", "", ""));
		return (set_pwd_and_res(home_path));
	}
	if (chdir(command->arg_list[0]) == -1)
		return (error_builtin("cd", command->arg_list[0], ""));
	return (set_pwd_and_res(getcwd(NULL, PWD_BUFFER_SIZE)));
}
