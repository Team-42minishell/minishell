#include "../includes/minishell.h"

int		get_key_idx(char *key)
{
	int		idx;

	idx = 0;
	while (g_envp[idx])
	{
		if (ft_startswith(g_envp[idx], key))
		{
			if (*(g_envp[idx] + ft_strlen(key)) == '=')
				return (idx);
		}
		idx++;
	}
	return (-1);
}

int		set_env(char *key, char *val)
{
	int		idx;
	char	*item;
	char	*temp;

	if (!key || !(*key))
		return (FALSE);
	idx = get_key_idx(key);
	temp = ft_strjoin(key, "=");
	item = ft_strjoin(temp, val);
	ft_free_str(&temp);
	if (idx == -1)
	{
		ft_realloc_doublestr(&g_envp, item);
		ft_free_str(&item);
	}
	else
	{
		ft_free_str(&g_envp[idx]);
		g_envp[idx] = item;
	}
	return (TRUE);
}

/*
** cmd_env: list environments.
*/

void	cmd_env(void)
{
	int	idx;

	set_exit_status(0);
	idx = -1;
	while (g_envp[++idx])
	{
		ft_putstr(g_envp[idx]);
		ft_putstr("\n");
	}
}
