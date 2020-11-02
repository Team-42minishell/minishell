/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:11:32 by sungslee          #+#    #+#             */
/*   Updated: 2020/11/03 01:04:14 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_tokenizer(char *error_token, char *msg, int res)
{
	int		i;

	ft_putstr_fd(SHELL, 2);
	i = -1;
	while (error_token[++i])
	{
		if (error_token[i] < 0 || error_token[i] == '\'')
		{
			ft_putendl_fd(QUOTE_ERROR, 2);
			set_res(res);
			return ;
		}
	}
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(error_token, 2);
	ft_putendl_fd("\'", 2);
	set_res(res);
}

void	error_execute(char *error_token, char *msg, int res)
{
	ft_putstr_fd(SHELL, 2);
	if (error_token)
	{
		ft_putstr_fd(error_token, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
	set_res(res);
}

void	error_builtin(char *cmd, char *arg, char *msg)
{
	int		error_num;

	error_num = errno;
	ft_putstr_fd(cmd, 2);
	if (ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "export") == 0)
		ft_putstr_fd(": '", 2);
	else
		ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	if (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "echo") == 0)
	{
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(error_num), 2);
	}
	else
		ft_putendl_fd(msg, 2);
	set_res(1);
	return ;
}
