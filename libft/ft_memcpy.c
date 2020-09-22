/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:47:28 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/08 19:48:44 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** - Copies 'n' bytes from memory area 'src' to memory area 'dst'.
** - Returns the original value of 'dst'.
*/

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	idx;

	if (dest == 0 && src == 0)
		return (dest);
	idx = 0;
	d = (char *)dest;
	s = (char *)src;
	while (idx < n)
	{
		d[idx] = s[idx];
		idx++;
	}
	return (dest);
}
