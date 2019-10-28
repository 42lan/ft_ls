/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 09:47:17 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/19 16:09:50 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string given as argument to
** create a “fresh” new string resulting from the successive applications of f.
*/

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	i = -1;
	if (!(new_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i] != '\0')
		new_str[i] = f(s[i]);
	return (new_str);
}
