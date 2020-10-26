/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:56:44 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/19 15:26:13 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_realloc(char **ptr, char c)
{
	char	*ret;
	int		size;

	if (!ptr)
		return (0);
	size = ft_strlen(*ptr);
	if (!(ret = (char *)ft_calloc(sizeof(char), size + 2)))
		return (0);
	ft_memcpy(ret, *ptr, size);
	ret[size] = c;
	//printf("size : %d string : %s\n", size, ret);
	ft_free(*ptr);
	*ptr = ret;
	return (ret);
}

