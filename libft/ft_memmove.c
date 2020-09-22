/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:51:50 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/08 19:54:51 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (dest > src)
	{
		if (n == 0 || dest == src)
			return (dest);
		d = (char *)dest;
		s = (char *)src;
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
