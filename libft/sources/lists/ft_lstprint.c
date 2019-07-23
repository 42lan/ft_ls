/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:55:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/23 11:57:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
