/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:21:06 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/17 17:50:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*push_end(t_file *head, t_file *file)
{
	t_file	*tmp;

	tmp = head;
	if (head == NULL)
		head = file;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = file;
		file->next = NULL;
	}
	return (head);
}
