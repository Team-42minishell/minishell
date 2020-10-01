#include "../includes/minishell.h"

void	builtin_env(void)
{
	int	idx;

	idx = -1;
	while (g_env_list[++idx].key)
	{
		ft_putstr_fd(g_env_list[idx].key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(g_env_list[idx].value, 1);
		ft_putstr_fd("\n", 1);
	}
}
