/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:06:38 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 09:51:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the element new at the beginning of the list alst.
*/

void	ft_lstadd_top(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		new->next = (*alst);
		(*alst) = new;
	}
}
