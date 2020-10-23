#include "../includes/minishell.h"

/*
int		execute_redirection(t_table *table, t_job *job)
{
}
*/
void	execute_command(t_command *command)
{
	if (ft_strcmp(command->cmd, "pwd") == 0)
		cmd_pwd();
	else if (ft_strcmp(command->cmd, "cd") == 0)
		cmd_cd(command);
	else if (ft_strcmp(command->cmd, "echo") == 0)
		cmd_echo(command);
	else
	{
		ft_putstr("fail\n");
	}
}

void	execute_job(t_table *table, t_job *job)
{
	int	p_id;

	p_id = 0;
	while (job)
	{
		// dup_pipe(job, p_id);
		/*
		if (!execute_redirection(table, job))
		{
			job = job->next;
			continue;
		}*/
		execute_command(&job->command);
		p_id++;
		job = job->next;
	}
	
}

void	execute_table(t_table	*table)
{
	int		status;

	g_maxfd = 2;
	if (!table || !table->job_list || !table->job_list->command.cmd)
		return ;
	//save_standart_fd(table);
	//g_pipes = make_pipes(table->job_list);
	//if (table->sep_type == SEMI)
	execute_job(table, table->job_list);
}