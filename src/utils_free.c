#include "../includes/minishell.h"

void	free_redir_list(t_redir *redir)
{
	t_redir	*tmp;

	if (!redir)
		return ;
	while (redir)
	{
		if (redir->sign)
			ft_free_str(&redir->sign);
		if (redir->arg)
			ft_free_str(&redir->arg);
		tmp = redir->next;
		ft_free(redir);
		redir = tmp;
	}
	
}

void	free_job_list(t_job *job)
{
	t_job	*tmp;

	if (!job)
		return ;
	while (job)
	{
		if (job->command.cmd)
			ft_free_str(&job->command.cmd);
		if (job->command.arg_list)
			free_double_pointer(job->command.arg_list);
		if (job->redir_list)
			free_redir_list(job->redir_list);
		tmp = job->next;
		ft_free(job);
		job = tmp;
	}
	
}
void	free_tables(t_table *table)
{
	t_table	*tmp;

	if (!table)
		return ;
	while (table)
	{
		if (table->job_list)
			free_job_list(table->job_list);
		tmp = table->next;
		ft_free(table);
		table = tmp;
	}
	ft_free(table);
}