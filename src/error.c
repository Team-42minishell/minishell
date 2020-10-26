#include "../includes/minishell.h"

void	error_builtin(char *cmd, char *arg, char *msg)
{
	int		error_num;

	error_num = errno;
	// ft_putstr_fd();
	// ft_putstr_fd();
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
