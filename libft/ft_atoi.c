/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 18:54:37 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/09 14:14:00 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long int	atoi;
	size_t				i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -sign : sign;
		i++;
	}
	atoi = 0;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		atoi = atoi * 10 + (str[i] - '0');
		if (atoi > 2147483647 && sign == 1)
			return (-1);
		if (atoi > 2147483648 && sign == -1)
			return (0);
		i++;
	}
	return (atoi * sign);
}
