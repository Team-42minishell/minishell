/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:41:24 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/31 00:41:25 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_startswith(const char *str, const char *sub)
{
	int		i;

	i = 0;
	while (sub[i] != '\0' && str[i] == sub[i])
		i++;
	return (sub[i] == '\0');
}
