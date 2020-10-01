#include "../includes/minishell.h"

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