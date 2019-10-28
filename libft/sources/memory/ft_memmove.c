/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:45:47 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:03:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies len bytes from string src to string dst. The two strings may overlap;
** the copy is always done in a non-destructive manner.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
	{
		while (len)
		{
			len--;
			*(unsigned char *)(dst + len) = *(unsigned char*)(src + len);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
