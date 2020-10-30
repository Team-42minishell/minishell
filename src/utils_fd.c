#include "../includes/minishell.h"

int		get_fd(t_redir *redir)
{
	int		fd;

	fd = -1;
	if (redir->error)
		return (-2);
	if (ft_strcmp(redir->sign, ">") == 0)
		fd = open(redir->arg, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (ft_strcmp(redir->sign, ">>") == 0)
		fd = open(redir->arg, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (ft_strcmp(redir->sign, "<") == 0)
		fd = open(redir->arg, O_RDWR);
	if (fd > g_maxfd)
		g_maxfd = fd;
	return (fd);
}

void	redirect_stdout_fd(t_table *table)
{
	// 1을 table->fd[1]로 파일 디스크럽터 복사
	dup2(table->fd[1], 1);
	// 2을 table->fd[2]로 파일 디스크럽터 복사
	dup2(table->fd[2], 2);
}

void	save_standard_fd(t_table *table)
{
	table->fd[0] = dup(0);
	table->fd[1] = dup(1);
	table->fd[2] = dup(2);
}

void	restore_standard_fd(t_table *table)
{
	dup2(table->fd[0], 0);
	dup2(table->fd[1], 1);
	dup2(table->fd[2], 2);
	close(table->fd[0]);
	close(table->fd[1]);
	close(table->fd[2]);
}

void	close_fd_and_pipes(void)
{
	while (g_maxfd > 2)
		close(g_maxfd--);
	free(g_pipes);
}
