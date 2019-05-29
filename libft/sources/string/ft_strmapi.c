/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 10:40:43 by amalsago          #+#    #+#             */
/*   Updated: 2019/04/29 10:26:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
