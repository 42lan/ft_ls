/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:26:34 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/19 19:20:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a “fresh” substring from the string given as argument.
** The substring begins a index start and is of size len. If start and len
** aren’t refering to a valid substring, the behavior is undefined.
** If the allocation fails, the function returns NULL.
*/

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_str;

	if (s)
	{
		i = 0;
		if (!(new_str = ft_strnew(len)))
			return (NULL);
		while (i < len)
			new_str[i++] = s[start++];
		return (new_str);
	}
	return (NULL);
}
