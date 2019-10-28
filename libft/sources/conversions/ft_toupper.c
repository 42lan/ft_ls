/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:45:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/19 19:37:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts a lower-case letter to the corresponding upper-case letter.
*/

int		ft_toupper(int c)
{
	return (ft_islower(c) ? c - ' ' : c);
}
