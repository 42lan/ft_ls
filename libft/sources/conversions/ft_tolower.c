/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:14:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 09:37:03 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts a upper-case letter to the corresponding lower-case letter.
*/

int		ft_tolower(int c)
{
	return (ft_isupper(c) ? c + ' ' : c);
}
