/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 19:00:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/06 15:50:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_litoa(intmax_t number)
{
	char		*str;
	size_t		length;

	if (number <= LLONG_MIN)
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
	length = ft_silen(number, 10);
	if (!(str = ft_strnew(length)))
		return (NULL);
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
