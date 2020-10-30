/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_doublestr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:13:08 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 22:13:09 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_doublestr(char **str)
{
	char	**ret;
	int		len;

	len = ft_len_doublestr(str);
	if (!(ret = (char **)ft_calloc(sizeof(char *), len + 1)))
		return (0);
	while (len--)
		if (!(ret[len] = ft_strdup(str[len])))
			return (0);
	return (ret);
}
