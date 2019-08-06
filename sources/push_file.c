/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:21:06 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/06 10:12:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*push_front(t_file *head, t_file *file)
{
	file->next = head;
	head = file;
	return (head);
}

t_file		*push_back(t_file *head, t_file *file)
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

/*
t_file		*push_file(t_file *head, t_file *file)
{
	t_file	*tmp;

	tmp = head;
	if (head == NULL)
		head = file;
	else
	{
		while (tmp->next != NULL)
		{
			if (ft_strcmp(file->name, tmp->name) > 0)
		}
	}
	return (head);
}
*/
