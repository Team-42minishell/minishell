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

int		ft_strlen(const char *s)
{
	int		len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
