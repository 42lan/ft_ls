/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_static.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 09:03:13 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/06 15:50:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_litoa_static(intmax_t number)
{
	static char		str[21];
	size_t			length;

	if (number <= LLONG_MIN)
	{
		ft_strcpy(str, "-9223372036854775808");
		return (str);
	}
	length = ft_silen(number, 10);
	str[length] = '\0';
	if (number == 0)
		str[0] = '0';
	else if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		str[--length] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
