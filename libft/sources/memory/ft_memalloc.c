/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 08:01:48 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/19 16:01:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a “fresh” memory area initialized to 0.
** If the allocation fails, the function returns NULL.
*/

void		*ft_memalloc(size_t size)
{
	void	*zone;

	if (!(zone = (void *)malloc(size)))
		return (NULL);
	ft_bzero(zone, size);
	return (zone);
}
