/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_converter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:34:51 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 21:34:53 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		open_handle(int *opened, char c)
{
	int		ret;

	ret = 0;
	if (!(*opened) && ft_is_set(c, "\'\""))
	{
		*opened = c;
		ret = 1;
	}
	else if (*opened && *opened == c)
	{
		*opened = 0;
		ret = 1;
	}
	return (ret);
}
