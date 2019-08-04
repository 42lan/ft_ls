/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 15:10:57 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/04 15:11:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstbsort(t_list *head)
{
	t_list	*i;
	t_list	*j;
	void	*tmp;

	if (head == NULL)
		return (0);
	i = head;
	while (i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (ft_memcmp(i->content, j->content, sizeof(char *)) > 0)
			{
				tmp = i->content;
				i->content = j->content;
				j->content = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}
