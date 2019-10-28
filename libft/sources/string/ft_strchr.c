/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:20:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:58:53 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of c (converted to a char) in the string pointed
** to by s. The terminating null character is considered to be part of the
** string; therefore if c is `\0', the functions locate the terminating `\0'.
*/

char		*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}
