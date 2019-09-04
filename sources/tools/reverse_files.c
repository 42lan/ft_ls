/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:32:20 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/04 13:32:41 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			reverse_files(t_file **head)
{
	t_file		*current;
	t_file		*next;
	t_file		*previous;

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
