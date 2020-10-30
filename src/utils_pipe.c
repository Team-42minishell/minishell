/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:12:58 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 20:14:41 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		count_job(t_job *job)
{
	int		cnt;

	cnt = 0;
	while (job)
	{
		cnt++;
		job = job->next;
	}
	return (cnt);
}

int		*make_pipes(t_job *job)
{
	int		pipe_cnt;
	int		idx;

	if (!(pipe_cnt = count_job(job) - 1))
		return (0);
	if (!(g_pipes = (int *)ft_calloc(sizeof(int), pipe_cnt * 2)))
		return (0);
	idx = -1;
	while (++idx < pipe_cnt)
		pipe(&g_pipes[idx * 2]);
	return (g_pipes);
}

void	dup_pipe(t_job *job, int idx)
{
	if (idx == 0 && !job->next)
		return ;
	if (idx == 0)
		dup2(g_pipes[idx * 2 + 1], 1);
	else if (!(job->next))
		dup2(g_pipes[(idx - 1) * 2], 0);
	else
	{
		dup2(g_pipes[(idx - 1) * 2], 0);
		dup2(g_pipes[idx * 2 + 1], 1);
	}
}
