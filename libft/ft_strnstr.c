/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:11:51 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/08 20:13:34 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** - Locates 1st occurrence of 'needle' in 'haystack'
**   searching not more than len.
** - Characters that appear after a `\0' character are not searched.
** - Returns
**   1) haystack, if needle is an empty string.
**   2) a pointer to first character of first occurrence of needle.
**   2) NULL, if needle occurs nowhere in haystack.
*/

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (s2[0] == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < n)
		{
			j++;
			if (s2[j] == 0)
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
