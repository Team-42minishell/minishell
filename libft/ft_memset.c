/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:55:29 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/08 19:56:26 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *cur;

	if (n == 0)
		return (b);
	cur = (unsigned char *)b;
	while (n > 0)
	{
		*cur = (unsigned char)c;
		cur++;
		n--;
	}
	return (b);
}
