/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:09:07 by sungslee          #+#    #+#             */
/*   Updated: 2020/08/08 20:30:34 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** - Computes the length of string 's'.
** - Returns # of characters that precede the terminating NUL character.
**   Returns either the same result as strlen() or maxlen, whichever is smaller.
*/

#include "libft.h"
#include "stdio.h"

int		ft_strlen(const char *s)
{
	int		len;

	if (!s)
	{
		//printf("%d %c\n", *s, *s);
		return (0);
	}
	len = 0;
	while (*s++){
		len++;
	}
	return (len);
}

/*
int		ft_strlen(const char *str)
{
	int		cnt;

	if (!str)
		return (0);
	cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	return (cnt);
}
*/