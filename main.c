/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:03:28 by daugier           #+#    #+#             */
/*   Updated: 2016/06/10 22:37:32 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	while (i < ac)
	{
		fd = open(av[i], O_RDONLY);
		while (get_next_line((int const)fd, &line))
		{
			ft_putstr("line :");
			ft_putendl(line);
			free(line);
		}
		close(fd);
		i++;
	}
	return (0);
}
