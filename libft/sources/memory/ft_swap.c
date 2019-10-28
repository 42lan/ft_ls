/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 08:52:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:03:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates a new "fresh" temporary variable of size bytes and swaps the
** content of a and b. Finally, frees temporary variable.
*/

void		ft_swap(void *a, void *b, size_t size)
{
	void	*tmp;

	if ((tmp = ft_memalloc(size)))
	{
		ft_memcpy(tmp, a, size);
		ft_memcpy(a, b, size);
		ft_memcpy(b, tmp, size);
	}
	ft_memdel(&tmp);
}
