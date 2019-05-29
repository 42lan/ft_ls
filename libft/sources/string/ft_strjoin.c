/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:08:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/03/31 16:57:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	if (!(new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	new_str = ft_strcpy(new_str, s1);
	new_str = ft_strcat(new_str, s2);
	return (new_str);
}
