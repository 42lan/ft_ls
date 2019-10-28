/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:55:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:07:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes out the elements of the list in one line terminated by NULL.
*/

void	ft_lstprint(t_list *list)
{
	while (list != NULL)
	{
		if (list->next == NULL)
		{
			ft_putstr(list->content);
			ft_putendl(" -> NULL");
		}
		else
		{
			ft_putstr(list->content);
			ft_putstr(" -> ");
		}
		list = list->next;
	}
}
