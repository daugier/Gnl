/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 18:03:28 by daugier           #+#    #+#             */
/*   Updated: 2016/05/21 18:43:37 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*int		main(int ac, char **av)
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
}*/

int	main(int argc, char ** argv)
{
	int		fd;
	int		fd2;
	char	*line;
	pid_t	child;
	char	n = '\n';

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	fd2 = open("me.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1 || fd2 == -1)
	{
		perror("open");
		close(fd);
		close(fd2);
		return (-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, &n, 1);					// attention si le fichier test n a pas de \n et que ca affiche une erreur c'est normal
		free(line);							// vous inquietez pas
	}
	close(fd);
	close(fd2);
	child = fork();
	if (child == 0)
	{
		char	*arg[] = {"/usr/bin/diff", NULL, "me.txt", NULL};

		arg[1] = argv[1];
		execve(arg[0], arg, NULL);
		exit(0);
	}
	else
		wait(NULL); // bad code I know ... but it's not the project
	(void)argc;
	(void)argv;
	return (0);
}
