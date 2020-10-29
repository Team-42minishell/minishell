#include "../includes/minishell.h"

void	cmd_exit(t_command *command)
{
	close_fd_and_pipes();
	ft_putendl_fd("exit", 1);
	set_res(0);
	if (command->arg_list)
	{
		if (!ft_is_number(command->arg_list[0]))
		{
			error_builtin("exit", command->arg_list[0], NUMERIC_REQUIRED);
			set_res(255);
		}
		else if (two_ptr_size(command->arg_list) > 1)
			return (error_builtin("exit", "\b\b \b\b", TOO_MANY_ARG));
		else
			set_res(ft_atoi(command->arg_list[0]));
	}
	exit(g_res);
	return ;
}
