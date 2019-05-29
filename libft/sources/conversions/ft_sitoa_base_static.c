/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa_base_static.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 10:51:14 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/06 17:43:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			check_sign(intmax_t *number, int base, char *str)
{
	if (*number < 0)
	{
		if (base == 10)
			str[0] = '-';
		*number *= -1;
	}
}

char				*ft_sitoa_base_static(intmax_t number, int base,
					int uppercase)
{
	static char		str[13];
	size_t			length;

	if (base < 2 || base > 36)
		return (NULL);
	length = (number < 0 && base != 10) ? ft_silen(number, base) - 1
										: ft_silen(number, base);
	str[length] = '\0';
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
