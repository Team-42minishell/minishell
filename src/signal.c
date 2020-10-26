#include "../includes/minishell.h"

void		sig_handler(int signo)
{
	char	buffer[MAXPATHLEN];
	char	*current_path;

	if (signo == SIGINT)
	{
		current_path = getcwd(buffer, MAXPATHLEN);
		ft_putstr("\b\b  \b\b\n");
		ft_putstr("catshell@");
		ft_putstr_fd(buffer, 1);
		ft_putstr(" ");
		set_exit_status(1);
	}
	if (signo == SIGQUIT)
		ft_putstr("\b\b  \b\b");
}

void		sig_execve_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		set_exit_status(130);
		signal(SIGINT, (void *)sig_handler);
	}
	else if (signo == SIGQUIT)
	{
		ft_putstr("Quit: 3\n");
		set_exit_status(131);
		signal(SIGQUIT, (void *)sig_handler);
	}
}

