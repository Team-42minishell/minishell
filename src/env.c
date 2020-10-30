/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:53:38 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 22:01:34 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_env(t_command *command)
{
	int	idx;

	if (command->arg_list)
		return (error_builtin("env", command->arg_list[0], TOO_MANY_ARG));
	idx = -1;
	while (g_envp[++idx])
	{
		ft_putstr(g_envp[idx]);
		ft_putstr("\n");
	}
	return (set_res(0));
}
