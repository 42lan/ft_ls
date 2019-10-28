/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 09:24:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/16 12:15:04 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFF_SIZE_GNL
#  define BUFF_SIZE_GNL 32

#  include <unistd.h>
#  include <limits.h>
#  include <string.h>
#  include "libft.h"

int		get_next_line(const int fd, char **line);

# endif
#endif
