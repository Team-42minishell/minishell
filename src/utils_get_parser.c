#include "../includes/minishell.h"

t_redir		*get_last_redir(t_table *table)
{
	t_job	*job;
	t_redir	*redir;

	job = get_last_job(table);
	if (!job)
		return (0);
	redir = job->redir_list;
	if (!redir)
		return (0);
	while (redir->next)
		redir = redir->next;
	return (redir);
}

t_table		*get_last_table(t_table *table)
{
	if (!table)
		return (0);
	while (table->next)
		table = table->next;
	return (table);
}

t_job		*get_last_job(t_table *table)
{
	t_job		*job;
	table = get_last_table(table);
	if (!table)
		return (0);
	job = table->job_list;
	if (!job)
		return (0);
	while (job->next)
		job = job->next;
	return (job);
}