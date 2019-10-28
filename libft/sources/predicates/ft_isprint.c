/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:06:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:32:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Perfoms printing (space inclusive) character test.
*/

int		ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
