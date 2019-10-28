/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:38:02 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/19 19:34:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string s to the given file descriptor fd.
*/

void	ft_putstr_fd(char const *s, int fd)
{
	if (s && fd)
		write(fd, s, ft_strlen(s));
}
