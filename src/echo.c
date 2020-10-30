#include "../includes/minishell.h"

void	print_echo_args(char **arg_list, int n_option)
{
	int		i;
	int		is_first_arg;

	if (!arg_list)
		return ;
	is_first_arg = TRUE;
	i = -1;
	while (arg_list[++i])
	{
		if (is_first_arg == FALSE)
			ft_putstr_fd(" ", 1);
		ft_putstr_fd(arg_list[i], 1);
		is_first_arg = FALSE;
	}
	set_res(0);
	if (n_option)
		return ;
	ft_putstr_fd("\n", 1);
}

void	cmd_echo(t_command *command)
{
	char	**start_arg;
	int		len;
	int		n_option;

	len = ft_len_doublestr(command->arg_list);
	start_arg = command->arg_list;
	n_option = FALSE;
	if (len == 0)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	if (ft_strcmp(command->arg_list[0], "-n") == 0)
	{
		if (len == 1)
			return ;
		n_option = TRUE;
		start_arg++;
	}
	print_echo_args(start_arg, n_option);
}