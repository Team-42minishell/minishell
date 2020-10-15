#include "../includes/minishell.h"

/*
** print_args_echo: print args.
** if -n option exist(n_option = 1), line ends without newline.
** otherwise(n_option = 0), line ends with newline.
*/

void	print_args_echo(int n_option, char **arg_list)
{
	int		idx;

	idx = 1;
	if (n_option != 0)
		idx = 0;
	while (arg_list[++idx])
	{
		ft_putstr_fd(arg_list[idx], 1);
		if (arg_list[idx + 1])
			ft_putstr_fd(" ", 1);
	}
	if (n_option != 0)
		ft_putstr_fd("\n", 1);
}

/*
** builtin_echo: print line. for example, line is "echo hello world".
** so, arg_list[0] must be "echo".
*/

void	builtin_echo(char *line)
{
	char	**arg_list;
	int		idx;
	int		n_option;

	set_exit_status(0);
	if (!(arg_list = ft_split(line, ' ')))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		set_exit_status(1);
		return ;
	}
	if (arg_list[1] == NULL)
	{
		ft_putstr_fd("\n", 1);
		free_double_pointer(arg_list);
		return ;
	}
	idx = 1;
	n_option = ft_strncmp(arg_list[1], "-n", ft_strlen(arg_list[1]));
	print_args_echo(n_option, arg_list);
	free_double_pointer(arg_list);
}
