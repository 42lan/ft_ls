/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 09:02:47 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/19 17:10:27 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a “fresh” string ending with '\0'.
** Each character of the string is initialized at '\0'.
** If the allocation fails the function returns NULL.
*/

char		*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	return (str);
}
