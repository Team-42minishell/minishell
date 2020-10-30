#include "../includes/minishell.h"

/*
** free_double_pointer
*/

void	free_double_pointer(char **args)
{
	int	idx;

	if (!args || !(*args))
		return ;
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
