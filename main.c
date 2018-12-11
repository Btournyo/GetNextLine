/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:24:45 by btournyo          #+#    #+#             */
/*   Updated: 2018/12/11 18:39:20 by btournyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	int		ret;
	int 	i;
	int		fd;
	char	*line = NULL;

	(void)argc;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		while (*line)
		{
			printf("%s\n", &line[i]);
			free(line);
		}
	}
	return (0);
}
