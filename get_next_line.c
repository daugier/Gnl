/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 15:48:42 by daugier           #+#    #+#             */
/*   Updated: 2016/04/07 15:05:21 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	if (!(ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	free(s1);
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	return (ptr);
}


int		read_next(int fd, char *buf, char **s2)
{
	int ret;


	bzero(buf, BUF_SIZE);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{	
		buf[ret] = '\0';
		*s2 = strjoin(*s2, buf);
		bzero(buf, BUF_SIZE);
	}
	return (ret);
}

int		get_next_line(int const fd, char **line)
{
	/*static t_next	next;*/
	static int		j = 0;
	static int		bb = 0;
	static int		i = 0;
	char			buf[BUF_SIZE + 1];
	static char		*s2;

	if (fd < 0 || BUF_SIZE < 1 || fd > 255 || line == NULL)
		return (-1);
	if (!bb)
	{
		if (!(s2 = (char *)malloc(sizeof(char) * 1)))
			return (0);
		s2[0] = '\0';
		if ((read_next(fd, buf, &s2)) < 0)
			return (-1);
		bb = 1;
	}
	i = j;
	if (!s2[j])
		return (0);
	while (s2[j] != '\n' && s2[j])
		j++;
	i = (j - i);
	if (!(*line = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	*line = ft_strncpy(*line, &(s2[j - i]), i);
	if (s2[j] == '\n')
	{
		j++;
		i++;
	}
	return (1);
}

/*int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("MAUVAIS FICHIER");
		return (0);
	}
	while (get_next_line((int const)fd, &line))
	{
		ft_putstr("line :");
		ft_putendl(line);
		free(line);
	}
	return (0);
}*/
