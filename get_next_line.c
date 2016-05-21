/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:48:42 by daugier           #+#    #+#             */
/*   Updated: 2016/05/21 19:21:45 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		read_next(int fd, char **buffer)
{
	int		ret;
	char	*buf;

	if (!(*buffer = (char*)malloc(sizeof(char) * 1)))
		return (0);
	if (!(buf = (char*)malloc(sizeof(char) * BUF_SIZE + 1)))
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		*buffer = ft_strjoin(*buffer, buf);
	}
	return (ret);
}

int		get_next_line(int const fd, char **line)
{
	static char		*buffer[MAX_FD];

	if (fd < MIN_FD || BUF_SIZE < 1 || line == NULL || read(fd, "LOL", 0))
		return (-1);
	if (!buffer[fd])
	{
		if (read_next(fd, &buffer[fd]) == -1)
			return (-1);
	}
	if (!(*line = (char*)malloc(sizeof(char) * 1)))
		return (0);
	if (!*buffer[fd])
		return (0);
	while (*buffer[fd] != '\n' && *buffer[fd] != '\0')
	{
		*line = ft_charjoin(*line, *buffer[fd]);
		buffer[fd]++;
	}
	if (*buffer[fd] == '\n')
		buffer[fd]++;
	return (1);
}
