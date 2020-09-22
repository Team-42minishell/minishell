/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:17:55 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/08 20:18:00 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	substr_len = ft_strlen(s);
	if (substr_len < start)
		start = substr_len;
	substr_len -= start;
	if (substr_len > len)
		substr_len = len;
	if (!(ptr = (char *)malloc(substr_len + 1)))
		return (NULL);
	ft_strlcpy(ptr, s + start, substr_len + 1);
	return (ptr);
}
