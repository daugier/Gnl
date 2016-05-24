/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:48:42 by daugier           #+#    #+#             */
/*   Updated: 2016/05/24 22:59:30 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_next(int fd, char **buffer)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (!(*buffer = (char*)malloc(sizeof(char) * 1)))
		return (0);
	*buffer[0] = '\0';
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		*buffer = ft_strjoin(*buffer, buf);
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buffer[MAX_FD];
	int				i;
	int				bsn;

	i = 0;
	bsn = 0;
	if (fd < MIN_FD || BUF_SIZE < 1 || line == NULL || read(fd, "", 0))
		return (-1);
	if (!buffer[fd])
		if (read_next(fd, &buffer[fd]) == -1)
			return (-1);
	if (buffer[fd][i] == '\0')
		return (0);
	while (buffer[fd][i] != '\n' && buffer[fd][i] != '\0')
		i++;
	if (!(*line = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	*line = ft_strncpy(*line, buffer[fd], i);
	if (buffer[fd][i] == '\n')
		i++;
	buffer[fd] = ft_strsub(buffer[fd], i, ft_strlen(buffer[fd] + i));
	return (1);
}
