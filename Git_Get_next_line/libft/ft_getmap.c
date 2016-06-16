/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:40:57 by daugier           #+#    #+#             */
/*   Updated: 2016/05/28 17:05:43 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getmap(int fd)
{
	int		i;
	int		ret;
	char	*str;
	char	buf[BUF_SIZE + 1];

	i = 0;
	str = (char*)malloc(sizeof(char) * 1);
	str[0] = '\0';
	ret = read(fd, buf, 1);
	if (ret == 0)
		str = NULL;
	str = ft_strjoin(str, buf);
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
	if (ret == -1)
	{
		free(str);
		str = NULL;
	}
	close(fd);
	return (str);
}
