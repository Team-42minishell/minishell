/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:58:47 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/19 17:10:05 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t size, size_t count)
{
	void		*addr;

	if (!(addr = malloc(size * count)))
		return (0);
	ft_memset(addr, 0, size * count);
	return (addr);
}
