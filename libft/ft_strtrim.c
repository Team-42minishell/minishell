/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:15:18 by sungslee          #+#    #+#             */
/*   Updated: 2020/07/09 13:44:33 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** - Allocates (with malloc) a copy of 's1' with the characters
**   specified in 'set' removed from beginning and end of string.
** - Returns 's1', the trimmed string, or NULL if the allocation fails.
*/

#include "libft.h"

int			is_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trim;
	int		front;
	int		end;
	int		len;

	if (s1 == NULL || set == NULL)
		return ((char *)s1);
	end = ft_strlen(s1) - 1;
	front = 0;
	while (front <= end && is_set(s1[front], set))
		front++;
	while (0 <= end && is_set(s1[end], set))
		end--;
	len = end > front ? end - front + 1 : 0;
	if (len <= 1)
		return (ft_strdup(""));
	s_trim = ft_calloc(sizeof(char), len + 1);
	if (s_trim == 0)
		return (0);
	ft_strlcpy(s_trim, s1 + front, len + 1);
	return (s_trim);
}
