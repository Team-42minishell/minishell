#include "../includes/minishell.h"

void	cmd_exit(t_command *command)
{
	close_fd_and_pipes();
	set_res(0);
	if (command->arg_list)
	{
		if (!ft_is_number(command->arg_list[0]))
		{
			error_builtin("exit", command->arg_list[0], NUMERIC_REQUIRED);
			set_res(255);
		}
		else if (ft_len_doublestr(command->arg_list) > 1)
			return (error_builtin("exit", "\b\b", TOO_MANY_ARG));
		else
		{
			ft_putendl_fd("exit", 1);
			set_res(ft_atoi(command->arg_list[0]));
		}
	}
	exit(g_res);
	return ;
}
