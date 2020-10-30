/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:12:11 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 22:12:11 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*find_value(char *key)
{
	int		key_idx;

	if (!g_envp)
		return (NULL);
	key_idx = get_key_idx(key);
	if (key_idx == -1)
		return (NULL);
	return (ft_strchr(g_envp[key_idx], '=') + 1);
}
