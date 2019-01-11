/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:15:46 by btournyo          #+#    #+#             */
/*   Updated: 2019/01/11 20:16:06 by btournyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# define MAX_FD 4864
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

int			get_next_line(const int fd, char **line);

#endif
