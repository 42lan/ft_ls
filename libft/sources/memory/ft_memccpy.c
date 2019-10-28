/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:42:20 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:03:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies bytes from string src to string dst. If the character c (as converted
** to an unsigned char) occurs in the string src, the copy stops and a pointer
** to the byte after the copy of c in the string dst is returned.
** Otherwise, n bytes are copied, and a NULL pointer is returned.
*/

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			if (((unsigned char *)src)[i] == (unsigned char)c)
				return (dst + i + 1);
			i++;
		}
	}
	return (NULL);
}
