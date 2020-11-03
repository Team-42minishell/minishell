/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 00:30:32 by sungslee          #+#    #+#             */
/*   Updated: 2020/11/03 00:34:08 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int			get_line(char **line)
{
	char	buf[2];
	char	*temp;

	ft_bzero(buf, 2);
	*line = ft_strdup("");
	temp = 0;
	while (*buf != '\n')
	{
		while (read(0, buf, 1) && *buf != '\n')
		{
			temp = ft_strjoin(*line, buf);
			free(*line);
			*line = temp;
		}
		if (ft_strlen(*line) == 0 && *buf != '\n')
			return (0);
	}
	return (1);
}
