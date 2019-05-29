/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:26:34 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/29 10:33:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
