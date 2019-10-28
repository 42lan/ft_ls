/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uilen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 12:38:21 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 09:45:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts and returns the number of digits in a given base of unsigned integer.
*/

size_t		ft_uilen(uintmax_t number, int base)
{
	size_t	length;

	length = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= base;
		++length;
	}
	return (length);
}
