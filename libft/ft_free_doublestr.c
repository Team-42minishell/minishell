/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_doublestr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:42:49 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/31 00:42:50 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_free_doublestr(char ***doublestr_addr)
{
	int		i;
	char	**doublestr;

	if (!doublestr_addr || !(*doublestr_addr))
		return (0);
	i = -1;
	doublestr = *doublestr_addr;
	while (doublestr[++i])
		ft_free_str(&doublestr[i]);
	ft_free(doublestr);
	*doublestr_addr = 0;
	return (1);
}
