/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:00:36 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/26 18:34:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Split the string str into tokens separated by characters in sep.
*/

char				*ft_strtok(char *str, const char *sep)
{
	int				i;
	static char		*static_str;

	if (!sep || (!str && !static_str))
		return (NULL);
	if (!str)
		str = static_str;
	str = str + ft_strspn(str, sep);
	i = ft_strcspn(str, sep);
	str[i] = '\0';
	static_str = &str[i] + 1 + ft_strspn(&str[i] + 1, sep);
	if (*static_str == '\0')
		static_str = NULL;
	return (str);
}
