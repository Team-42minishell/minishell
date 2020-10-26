#include "../includes/minishell.h"

/*
** cmd_env: list environments.
** if environment's value is not set, that environment is not displayed
** with 'env' command.
** but, with 'export' command, that environment will be displayed.
*/

void	cmd_env(void)
{
	int	idx;

	set_exit_status(0);
	idx = -1;
	while (g_env_list[++idx].key)
	{
		if (g_env_list[idx].value == NULL)
			continue ;
		ft_putstr_fd(g_env_list[idx].key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(g_env_list[idx].value, 1);
		ft_putstr_fd("\n", 1);
	}
}
