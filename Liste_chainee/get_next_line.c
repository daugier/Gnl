/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:48:42 by daugier           #+#    #+#             */
/*   Updated: 2016/06/18 23:41:30 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_next	*ft_get_good_list(t_next **list, int fd)
{
	t_next	*cpy;

	if (!*list)
	{
		if (!(*list = (t_next*)ft_memalloc(sizeof(t_next))))
			return (NULL);
		(*list)->fd = fd;
		return (*list);
	}
	cpy = *list;
	while (cpy->fd != fd)
	{
		if (!cpy->next)
		{
			if (!(cpy->next = (t_next*)ft_memalloc(sizeof(t_next))))
				return (NULL);
			cpy->next->fd = fd;
			return (cpy->next);
		}
		cpy = cpy->next;
	}
	return (cpy);
}

static int		ft_free(t_next **list, int fd)
{
	t_next	*cpy;
	t_next	*tmp;

	cpy = *list;
	tmp = *list;
	if ((*list)->fd == fd)
		(*list) = (*list)->next;
	else
	{
		while (cpy->next->fd != fd && cpy->next)
			cpy = cpy->next;
		tmp = cpy->next;
		cpy->next = cpy->next->next;
	}
	free(tmp->buff);
	free(tmp);
	tmp = NULL;
	return (0);
}

static int		read_next(int fd, char **buffer)
{
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];

	if (!(*buffer = (char*)malloc(sizeof(char) * 1)))
		return (0);
	*buffer[0] = '\0';
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = *buffer;
		*buffer = ft_strjoin(tmp, buf);
		free(tmp);
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
	static t_next	*list = NULL;
	int				i;
	t_next			*cpy;
	char			*tmp;

	i = 0;
	if (fd < 0 || !line)
		return (-1);
	cpy = ft_get_good_list(&list, fd);
	if (!cpy->buff)
		if (read_next(fd, &cpy->buff) == -1)
			return (-1);
	if (!cpy->buff[i])
		return (ft_free(&list, fd));
	while (cpy->buff[i] != '\n' && cpy->buff[i])
		i++;
	if (!(*line = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	*line = ft_strncpy(*line, cpy->buff, i);
	if (cpy->buff[i] == '\n')
		i++;
	tmp = cpy->buff;
	cpy->buff = ft_strsub(tmp, i, ft_strlen(tmp + i));
	free(tmp);
	return (1);
}
