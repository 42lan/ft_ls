/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:40:43 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/19 16:11:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string passed as argument by
** giving its index as first argument to create a“fresh” new string resulting
** from the successive applications of f.
*/

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str_new;

	if (!s || !f)
		return (NULL);
	if (!(str_new = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		str_new[i] = f(i, s[i]);
	return (str_new);
}
