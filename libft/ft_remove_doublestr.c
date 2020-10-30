/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_doublestr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:43:56 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/31 00:43:59 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_remove_doublestr(char **str, int idx)
{
	char	**ret;
	int		len;
	int		i;
	int		j;

	len = ft_len_doublestr(str);
	if (!(ret = (char **)ft_calloc(sizeof(char *), len)))
		return (0);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i != idx && !(ret[j++] = ft_strdup(str[i])))
			return (0);
		i++;
	}
	ft_free_doublestr(&str);
	return (ret);
}
