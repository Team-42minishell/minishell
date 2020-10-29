#include "../includes/minishell.h"

int		execute_redirection(t_table *table, t_job *job)
{
	t_redir		*redir;
	int			fd;

	if (!(job->next))
		redirect_stdout_fd(table);
	if (!(redir = job->redir_list))
		return (1);
	while (redir)
	{
		if ((fd = get_fd(redir)) >= STDNRM)
			dup2(fd, redir->fd);
		else if (fd == REDIRAMB)
			error_execute(redir->arg, REDIR_AMBIGOUS, 1);
		else if (fd == FDERR)
			error_execute(redir->arg, NO_SUCH_ENTRY, 1);
		if (fd == REDIRAMB || fd == FDERR)
			return (0);
		redir = redir->next;
	}
	return (1);
}

void	execute_command(t_command *command)
{
	if (ft_strcmp(command->cmd, "pwd") == 0)
		cmd_pwd();
	else if (ft_strcmp(command->cmd, "cd") == 0)
		cmd_cd(command);
	else if (ft_strcmp(command->cmd, "echo") == 0)
		cmd_echo(command);
	else if (ft_strcmp(command->cmd, "env") == 0)
		cmd_env();
	else if (ft_strcmp(command->cmd, "export") == 0)
		cmd_export(command);
	else if (ft_strcmp(command->cmd, "unset") == 0)
		cmd_unset(command);
	else if (ft_strcmp(command->cmd, "exit") == 0)
		cmd_exit(command);
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
		if (!execute_redirection(table, job))
		{
			job = job->next;
			continue;
		}
		execute_command(&job->command);
		p_id++;
		job = job->next;
	}
	return ;
}

void	execute_table(t_table	*table)
{
	int		status;

	g_maxfd = 2;
	if (!table || !table->job_list || !table->job_list->command.cmd)
		return ;
	save_standard_fd(table);
	if (table->sep_type == SEMI || table->sep_type == NONE)
		execute_job(table, table->job_list);
	while (wait(&status) > 0)
		g_res = WEXITSTATUS(status);
	restore_standart_fd(table);
	close_fd_and_pipes();
	//g_pipes = make_pipes(table->job_list);;
}
