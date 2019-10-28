/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:39:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 09:40:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts an unsigned integer value using the specified base to a new
** allocated null-terminated string. The case of string can be specified by
** uppercase.
*/

char			*ft_uitoa_base(uintmax_t number, int base, int uppercase)
{
	char		*str;
	size_t		length;

	if (base < 2 || base > 36)
		return (NULL);
	length = ft_uilen(number, base);
	if (!(str = ft_strnew(length)))
		return (NULL);
	if (number == 0)
		str[0] = '0';
	else if (uppercase == 1)
		while (number > 0)
		{
			str[--length] = BASE_UPPER[number % base];
			number /= base;
		}
	else
		while (number > 0)
		{
			str[--length] = BASE_LOWER[number % base];
			number /= base;
		}
	return (str);
}
