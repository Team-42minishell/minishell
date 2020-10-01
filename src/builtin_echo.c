#include "../includes/minishell.h"

/*
** builtin_echo: print line. for example, line is "echo hello world".
** so, arg_list[0] must be "echo".
** if -n option exist, line ends without newline.
** otherwise, line ends with newline.
*/

void	builtin_echo(char *line)
{
	char	**arg_list;
	int		idx;
	int		n_option;

	if (!(arg_list = ft_split(line, ' ')))
	{
		ft_putstr_fd("error: can't allocate memory.\n", 2);
		return ;
	}
	if (arg_list[1] == NULL)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	idx = 1;
	n_option = ft_strncmp(arg_list[1], "-n", ft_strlen(arg_list[1]));
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
	free_double_pointer(arg_list);
}
