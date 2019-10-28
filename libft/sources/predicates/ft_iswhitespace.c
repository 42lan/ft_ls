/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:09:41 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:57:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Perfoms white-space character test.
** This includes the following standard characters:
** ``\t''   ``\n''    `` ''
*/

int		ft_iswhitespace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}
