/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:40:40 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/08 19:42:56 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;
	size_t	idx;

	idx = 0;
	d = (char *)dest;
	s = (char *)src;
	while (idx < n)
	{
		d[idx] = s[idx];
		if ((unsigned char)d[idx] == (unsigned char)c)
			return ((char *)d + idx + 1);
		idx++;
	}
	return (NULL);
}
