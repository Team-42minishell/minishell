#include "../includes/minishell.h"

/*
** cmd_env: list environments.
*/

void	cmd_env(void)
{
	int	idx;

	set_res(0);
	idx = -1;
	while (g_envp[++idx])
	{
		ft_putstr(g_envp[idx]);
		ft_putstr("\n");
	}
}
