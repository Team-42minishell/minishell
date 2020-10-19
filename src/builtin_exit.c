#include "../includes/minishell.h"

/*
** check_if_arg_is_num: check whether exit's arg is number.
** if it is number, it works.
** if it is not number, programs occurs error and return 255.
*/

void	check_if_arg_is_num(char *str)
{
	int		idx;

	idx = -1;
	if (str[0] == '-' || str[0] == '+')
		idx++;
	while (str[++idx])
	{
		if (!(str[idx] >= '0' && str[idx] <= '9'))
		{
			ft_putstr_fd("error: exit: ", 2);
			ft_putstr_fd(str, 2);
			ft_putstr_fd(": numeric argument required.\n", 2);
			exit(255);
		}
	}
}

/*
** builtin_exit: when the command is 'exit', the shell will be exited.
** and it will return 0 if it works normally.
** but, if there is an error, the shell will return 1.
** if 'exit' command has argument, the shell will return the argument.
** for example, if the command is 'exit 128', the shell will return 128.
*/

void	builtin_exit(char *line)
{
	char	**arg_list;

	if (!(arg_list = ft_split(line, ' ')))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		set_exit_status(1);
		return ;
	}
	if (two_ptr_size(arg_list) > 2)
	{
		ft_putstr_fd("error: exit: too many arguments.\n", 2);
		set_exit_status(1);
		return ;
	}
	ft_putstr("exit\n");
	if (arg_list[1] == NULL)
		exit(0);
	check_if_arg_is_num(arg_list[1]);
	exit(ft_atoi(arg_list[1]) % 256);
}
