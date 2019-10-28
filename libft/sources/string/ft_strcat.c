/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:05:14 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:58:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Append a copy of the null-terminated string s2 to the end of the
** null-terminated string s1, then add a terminating `\0'. The string s1 must
** have sufficient space to hold the result.
*/

char		*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0')
		s1[len++] = s2[i++];
	s1[len] = '\0';
	return (s1);
}
