/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 14:04:29 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:14:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes n zeroed bytes to the string s. If n is zero function does nothing.
*/

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*p_s;

	if (n != 0)
	{
		p_s = (unsigned char *)s;
		ft_memset(p_s, 0, n);
	}
}
