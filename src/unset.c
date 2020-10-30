/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:08:44 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 22:08:45 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		unset_env(char *arg)
{
	int		idx;

	if (!arg || !(*arg) || ft_strchr(arg, '=') || ft_is_num(arg[0]))
		return (FALSE);
	idx = get_key_idx(arg);
	if (idx == -1)
		return (TRUE);
	if (!(g_envp = ft_remove_doublestr(g_envp, idx)))
		return (FALSE);
	return (TRUE);
}

void	cmd_unset(t_command *cmd)
{
	int		idx;

	set_res(0);
	if (!cmd->arg_list)
		return ;
	idx = -1;
	while (cmd->arg_list[++idx])
	{
		if (unset_env(cmd->arg_list[idx]) == FALSE)
			error_builtin("unset", cmd->arg_list[idx], INVALID_IDENTIFIER);
	}
}
