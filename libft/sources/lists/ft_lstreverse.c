/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 14:28:09 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/02 11:23:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
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
