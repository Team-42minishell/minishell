/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:36:50 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 21:38:05 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void		cmd_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 1024);
	if (!path)
		return (error_builtin("env", "", FAIL_TO_GET_PATH));
	ft_putendl_fd(path, 1);
	ft_free_str(&path);
	return (set_res(0));
}
