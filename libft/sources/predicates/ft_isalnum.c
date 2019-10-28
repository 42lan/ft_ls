/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:29:10 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:32:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Perfoms alphanumeric character test.
*/

int		ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
