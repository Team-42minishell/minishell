/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:47:50 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 16:47:51 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			check_char(char **str, char **format)
{
	char		c;

	c = *(*format);
	if (c == ' ' && !ft_is_space(*(*str)))
		return (0);
	if (c == 'c' && !ft_is_alpha(*(*str)))
		return (0);
	if (c == 'd' && !ft_is_num(*(*str)))
		return (0);
	if (c == '*' && !ft_is_print(*(*str)))
		return (0);
	if (c == '*' && ft_is_space(*(*str)))
		return (0);
	*str = *str + 1;
	*format = *format + 1;
	return (1);
}

void		handling_others(char **str, char **format)
{
	char		c;
	char		duple;

	c = *(*format);
	duple = 0;
	if (!check_char(str, format))
		*format = *format + 1;
	if (*(*format) == '+')
		duple = 1;
	if (*(*format) == '?' && *(*format + 1) == '+')
		duple = 1;
	while (duple && c == ' ' && ft_is_space(*(*str)))
		*str = *str + 1;
	while (duple && c == 'c' && ft_is_alpha(*(*str)))
		*str = *str + 1;
	while (duple && c == 'd' && ft_is_num(*(*str)))
		*str = *str + 1;
	while (duple && c == '*' && ft_is_print(*(*str)) && !ft_is_space(*(*str)))
		*str = *str + 1;
	while (ft_is_set(*(*format), "?+"))
		*format = *format + 1;
}

int			ft_is_format(char *str, char *format)
{
	int			valid;

	valid = 1;
	while (*format && valid)
	{
		if (!ft_is_set(*format, "[cd* "))
			return (0);
		handling_others(&str, &format);
	}
	return ((!(*str) && !(*format) && valid) ? 1 : 0);
}
