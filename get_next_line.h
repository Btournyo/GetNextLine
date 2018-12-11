/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btournyo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:33:38 by btournyo          #+#    #+#             */
/*   Updated: 2018/12/11 18:40:09 by btournyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFF_SIZE
#define BUFF_SIZE 42

#include <stdlib.h>
#include <string.h>
#include "./libft/libft.h"

int get_next_line(const int fd, char **line);

#endif
