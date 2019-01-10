/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:52:30 by flbeaumo          #+#    #+#             */
/*   Updated: 2018/12/20 15:47:49 by btournyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			cut_line(char **s, char **line)
{
	char	*tmp;
	int		len;

	len = ft_strclen(*s, '\n');
	if (ft_strchr(*s, '\n'))
	{
		if (!(*line = ft_strsub(*s, 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(*s + len + 1)))
			return (-1);
		free(*s);
		*s = tmp;
		if (s[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		if (!(*line = ft_strdup(*s)))
			return (-1);
		ft_strdel(s);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*s[MAX_FD];
	char		buff[BUFF_SIZE + 1];
	int			ret;
	char		*tmp;

	if (line == NULL || fd < 0 || fd > 1023)
		return (-1);
	if (!s[fd])
		if (!(s[fd] = ft_strnew(1)))
			return (-1);
	while ((ret = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(tmp = ft_strjoin(s[fd], buff)))
			return (-1);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			return (cut_line(&s[fd], line));
	}
	if (ret < 0)
		return (-1);
	if ((!s[fd] && (ret == 0)) || s[fd][0] == '\0')
		return (0);
	return (cut_line(&s[fd], line));
}
