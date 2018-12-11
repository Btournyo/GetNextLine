/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:58:08 by btournyo          #+#    #+#             */
/*   Updated: 2018/12/11 18:38:11 by btournyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

/*char *ft_strjoin_free(char const *s1, char const *s2, size_t n)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;
	size_t			size;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if ((str = (char *)malloc(sizeof(char) * (size))) == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}*/

char *read_fd(const int fd, char *save, char *buf)
{
	int ret;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		save = buf;
	}
/*	while (read(fd, buf + i, 1) == 1) on lit les char un par un et on s'arrete au \n
	{
		if (buf[i++] == '\n')
			break;
		save[i] = read(fd, save + i, BUFF_SIZE);
		i++;
	}
	buf[i] = '\0';*/
	return (save);
}

int get_next_line(const int fd, char **line)
{
	static char *save = NULL;	
	char		buf[BUFF_SIZE + 1];
	int i;
//	char *temp;

	i = 0;
	if (line == NULL || fd < 0 || read(fd, buf, BUFF_SIZE) < 0)
		return (-1);
	save = read_fd(fd, save, buf);
	while (save[i])
	{
		if (save[i] == '\n')
		{
			*line = ft_strsub(save, save[0], i); 
			save = ft_strsub(save, i, ft_strlen(save) - i + 1);
		}
		i++;
	}
/*	ft_memmove(save[i], *line, BUFF_SIZE - i);
	*save = ft_strjoin_free(*line; save, BUFF_SIZE - i);
	free();
	return (1);*/
	return (0);
}

//	ft_strchr(*save[i], '\n');
