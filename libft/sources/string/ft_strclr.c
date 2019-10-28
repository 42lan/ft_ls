/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 09:23:09 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/19 16:06:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Sets every character of the string to the value ’\0’.
*/

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero((void *)s, ft_strlen(s));
}
