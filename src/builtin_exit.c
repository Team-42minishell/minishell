#include "../includes/minishell.h"

void	builtin_exit(char *line)
{
	char	**arg_list;
	int		idx;

	if (!(arg_list = ft_split(line, ' ')))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		return ;
	}
	if (two_ptr_size(arg_list) > 2)
	{
		ft_putstr_fd("error: exit: too many arguments.\n", 2);
		return ;
	}
	ft_putstr("exit\n");
	if (arg_list[1] == NULL)
		exit(0);
	idx = -1;
	if (arg_list[1][0] == '-' || arg_list[1][0] == '+')
		idx++;
	while (arg_list[1][++idx])
	{
		if (!(arg_list[1][idx] >= '0' && arg_list[1][idx] <= '9'))
		{
			ft_putstr_fd("error: exit: ", 2);
			ft_putstr_fd(arg_list[1], 2);
			ft_putstr_fd(": numeric argument required.\n", 2);
			exit(255);
		}
	}
	exit(ft_atoi(arg_list[1]) % 256);
}
