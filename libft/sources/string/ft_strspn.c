/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:32:11 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/26 16:47:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of charactes found in the string s that contains only
** characters from the charset.
*/

size_t			ft_strspn(const char *s, const char *charset)
{
	size_t		i;
	size_t		found;

	i = 0;
	while (s[i])
	{
		found = 0;
		while (ft_strchr(charset, s[i]))
		{
			found = 1;
			break ;
		}
		if (found == 0)
			break ;
		i++;
	}
	return (i);
}
