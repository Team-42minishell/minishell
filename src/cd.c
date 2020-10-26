#include "../includes/minishell.h"

void	cmd_cd(t_command *command)
{
	char	*home_path;
	int		argc;

	argc = two_ptr_size(command->arg_list);
	/*
	if (argc == 0)
	{

	}
	*/
	if (chdir(command->arg_list[0]) == -1)
	{
		ft_putstr_fd(command->arg_list[0], 1);
		ft_putstr_fd("fail cd\n", 1);
		return ;
	}
}