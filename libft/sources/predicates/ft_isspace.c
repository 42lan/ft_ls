/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:39:00 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:57:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Perfoms white-space character test.
** This includes the following standard characters:
** ``\t''   ``\n''    ``\v''    ``\f''    ``\r''    `` ''
*/

int		ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
