/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 08:59:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:04:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a “fresh” null-terminated string representing the
** integer n given as argument. Negative numbers are be supported.
** If the allocation fails, the function returns NULL.
*/

char			*ft_itoa(int n)
{
	char		*str;
	size_t		length;
	intmax_t	nbr;

	nbr = n;
	length = ft_silen(nbr, 10);
	if (!(str = ft_strnew(length)))
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[--length] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
