/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 16:50:13 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/26 17:08:11 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of charactes found in the string s that not contains
** characters from the charset.
*/

size_t			ft_strcspn(const char *s, const char *charset)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		while (ft_strchr(charset, s[i]) == NULL)
			++i;
		if (ft_strchr(charset, s[i]))
			break ;
		++i;
	}
	return (i);
}
