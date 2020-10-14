#include "../includes/minishell.h"

int		two_ptr_size(char **ptr)
{
	int		i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

/*
** free_double_pointer
*/

void	free_double_pointer(char **args)
{
	int	idx;

	idx = -1;
	while (args[++idx])
		free(args[idx]);
	free(args);
}

/*
** set_exit_status
*/

void	set_exit_status(int status)
{
	g_exit_status = status;
}
