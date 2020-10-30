/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:53:31 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 16:53:33 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void		handle_quote(int *quote, char c)
{
	if (!(*quote))
		*quote = c;
	else if (*quote == c)
		*quote = 0;
}

int				right_bracket(char *src)
{
	int		i;
	int		quote;

	i = -1;
	quote = 0;
	while (src[++i])
	{
		if (ft_is_set(src[i], "\'\""))
			handle_quote(&quote, src[i]);
		if (!(src[i] == '$' && src[i + 1] == '{' && quote != '\''))
			continue;
		i += 2;
		if (src[i] == '?' && src[i + 1] != '}')
			return (0);
		while (src[i] && !ft_is_set(src[i], "{}\'\""))
			i++;
		if (!src[i] || src[i] != '}')
			return (0);
	}
	return (1);
}

int				right_quote(char *src)
{
	int		i;
	int		quote;

	i = -1;
	quote = 0;
	while (src[++i])
	{
		if (ft_is_set(src[i], "\'\""))
		{
			if (!quote)
				quote = src[i];
			else if (quote == src[i])
				quote = 0;
		}
	}
	return (quote == 0);
}
