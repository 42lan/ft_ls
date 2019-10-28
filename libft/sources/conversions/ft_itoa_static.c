/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_static.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:45:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:00:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a null-terminated string representing the integer n given as
** argument. Negative numbers are be supported.
*/

char				*ft_itoa_static(int n)
{
	static char		str[12];
	size_t			length;

	length = ft_silen(n, 10);
	str[length] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n == INT_MIN)
		ft_strcpy(str, "-2147483648");
	else if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[--length] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
