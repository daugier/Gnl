/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:48:42 by daugier           #+#    #+#             */
/*   Updated: 2016/06/10 22:42:43 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strncpy_gnl(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i++] = '\0';
	return (dst);
}

static char		*ft_strsub_gnl(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cpy;

	if (!s)
		return (NULL);
	if (!(cpy = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		cpy[i++] = s[start++];
	cpy[i] = '\0';
	free((char*)s);
	return (cpy);
}

static char		*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(s1) +
					ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free((char*)s1);
	return (str);
}

static int		read_next(int fd, char **buffer)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	if (!(*buffer = (char*)malloc(sizeof(char) * 1)))
		return (0);
	*buffer[0] = '\0';
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*buffer = ft_strjoin_gnl(*buffer, buf);
	}
	if (ret == -1)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (ret);
}

int				get_next_line(int const fd, char **line)
{
	static char		*buffer[MAX_FD];
	int				i;

	i = 0;
	if (fd < MIN_FD || BUF_SIZE < 1 || line == NULL)
		return (-1);
	if (!buffer[fd])
		if (read_next(fd, &buffer[fd]) == -1)
			return (-1);
	if (buffer[fd][i] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (0);
	}
	while (buffer[fd][i] != '\n' && buffer[fd][i] != '\0')
		i++;
	if (!(*line = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	*line = ft_strncpy_gnl(*line, buffer[fd], i);
	if (buffer[fd][i] == '\n')
		i++;
	buffer[fd] = ft_strsub_gnl(buffer[fd], i, ft_strlen(buffer[fd] + i));
	return (1);
}
