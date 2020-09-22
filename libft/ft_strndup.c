/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:17:30 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/15 19:18:12 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s);
	if (len > n)
		len = n;
	if (!(ptr = (char *)malloc(len + 1)))
		return (NULL);
	ptr[len] = '\0';
	return (ft_memcpy(ptr, s, len));
}
