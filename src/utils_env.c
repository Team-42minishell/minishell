#include "../includes/minishell.h"

char	*find_value(char *key)
{
	t_env	*current;
	int		len;

	current = g_env_list;
	len = ft_strlen(key);
	while (current->key != NULL && current->value != NULL)
	{
		if (ft_strncmp(key, current->key, len) == 0)
			return (current->value);
		current++;
	}
	return (NULL);
}

/*
** get_number_envs: return the number of environments.
*/

int		get_number_envs(void)
{
	int		idx;

	idx = -1;
	while (g_env_list[++idx].key)
		;
	return (idx);
}
