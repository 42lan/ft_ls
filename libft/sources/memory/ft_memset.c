/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 09:59:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:20:50 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes len bytes of value c (converted to an unsigned char) to the string b.
*/

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p_b;

	p_b = (unsigned char *)b;
	while (len > 0)
	{
		*p_b++ = c;
		len--;
	}
	return (b);
}
