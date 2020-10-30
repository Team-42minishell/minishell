/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungslee <sungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:11:45 by sungslee          #+#    #+#             */
/*   Updated: 2020/10/30 22:11:46 by sungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int	handle_line(char **line, char **buffer, char *next_line)
{
	char	*tmp;

	if (next_line != NULL)
	{
		*line = ft_strndup(*buffer, next_line - *buffer);
		tmp = ft_strndup(next_line + 1, ft_strlen(next_line + 1));
		free(*buffer);
		*buffer = tmp;
		return (1);
	}
	if (*buffer != NULL)
	{
		*line = *buffer;
		*buffer = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*buffer[OPEN_MAX];
	char			tmp_buf[BUFFER_SIZE + 1];
	char			*next_line;
	char			*tmp;
	int				len;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	while ((next_line = ft_strchr(buffer[fd], '\n')) == 0
				&& (len = read(fd, tmp_buf, BUFFER_SIZE)) > 0)
	{
		tmp_buf[len] = 0;
		if (buffer[fd] == NULL)
			tmp = ft_strndup(tmp_buf, len);
		else
			tmp = ft_strjoin(buffer[fd], tmp_buf);
		if (buffer[fd] != 0)
			free(buffer[fd]);
		buffer[fd] = tmp;
	}
	if (len < 0)
		return (-1);
	return (handle_line(line, &buffer[fd], next_line));
}
