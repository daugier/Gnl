/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:03:28 by daugier           #+#    #+#             */
/*   Updated: 2016/05/24 19:13:34 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	if (ac >= 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			printf("MAUVAIS FICHIER");
			return (0);
		}
	}
	while (get_next_line((int const)fd, &line))
	{
		ft_putstr("line :");
		ft_putendl(line);
		free(line);
	}
	return (0);
}
