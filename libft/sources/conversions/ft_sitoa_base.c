/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 00:39:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:01:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts a signed integer value using the specified base to a new allocated
** null-terminated string. The case of string is specified by uppercase.
*/

static void			check_sign(intmax_t *number, int base, char *str)
{
	if (*number < 0)
	{
		if (base == 10)
			str[0] = '-';
		*number *= -1;
	}
}

char				*ft_sitoa_base(intmax_t number, int base, int uppercase)
{
	char			*str;
	size_t			length;

	if (base < 2 || base > 36)
		return (NULL);
	length = (number < 0 && base != 10) ? ft_silen(number, base) - 1
										: ft_silen(number, base);
	if (!(str = ft_strnew(length)))
		return (NULL);
	check_sign(&number, base, str);
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
