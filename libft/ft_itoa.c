/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:07:57 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/08 19:34:18 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	itoa_len(int n, int base)
{
	size_t len;

	len = n < 0 ? 2 : 1;
	while (n > base - 1 || n < -(base - 1))
	{
		n /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*str;
	char	*tmp;
	size_t	len_itoa;

	len_itoa = itoa_len(n, 10);
	if (!(str = (char *)ft_calloc(len_itoa + 1, sizeof(char))))
		return (NULL);
	tmp = str;
	if (n < 0)
	{
		*tmp++ = '-';
		len_itoa--;
	}
	while (len_itoa-- > 0)
	{
		*(tmp + len_itoa) = (n % 10) >= 0 ? (n % 10) + '0' : -(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
