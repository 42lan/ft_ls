/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:12:12 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:48:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Computes and returns the length of the string s1.
*/

size_t		ft_strlen(const char *s1)
{
	size_t	len;

	len = 0;
	while (*s1++)
		len++;
	return (len);
}
