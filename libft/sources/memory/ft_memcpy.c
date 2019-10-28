/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 15:53:20 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:04:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies n bytes from memory area src to memory area dst. If dst and src
** overlap, behavior is undefined.
*/

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*src_str;
	char		*dst_str;

	i = -1;
	src_str = (const char *)src;
	dst_str = (char *)dst;
	while (++i < n)
		dst_str[i] = src_str[i];
	return (dst_str);
}
