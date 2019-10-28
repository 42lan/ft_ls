/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:28:09 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:12:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Reverse the order of elemets of the given linked list.
**
** Time complexity: O(n)
** Space complexity: O(1)
*/

void		ft_lstreverse(t_list **head)
{
	t_list	*current;
	t_list	*next;
	t_list	*previous;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	current = *head;
	next = NULL;
	previous = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
}
