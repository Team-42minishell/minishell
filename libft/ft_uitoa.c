/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:14:28 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/08 18:14:30 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned int n)
{
	unsigned int	div;
	unsigned int	len;
	char			*res;

	div = n;
	len = (n == 0) ? 1 : 0;
	while (div != 0)
	{
		div = div / 10;
		len++;
	}
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (0);
	res[len] = '\0';
	res[0] = '0';
	while (n != 0)
	{
		len--;
		res[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
