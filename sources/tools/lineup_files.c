/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineup_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:03:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/21 09:45:50 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		update_head(t_file **head, t_file *dir_list, t_file *file_list,
				t_file *lastreg)
{
	if (lastreg == NULL)
		*head = dir_list;
	else
	{
		lastreg->next = dir_list;
		*head = file_list;
	}
}

static void		lineup_handler(t_file **list, t_file **curr, t_file **last,
				t_file *next)
{
	if ((*list) == NULL)
	{
		(*list) = (*curr);
		(*curr) = next;
		(*last) = (*list);
		(*last)->next = NULL;
	}
	else
	{
		(*last)->next = (*curr);
		(*last) = (*curr);
		(*last)->next = NULL;
		(*curr) = next;
	}
}

void			lineup_files(t_file **head)
{
	t_file		*curr;
	t_file		*next;
	t_file		*file_list;
	t_file		*dir_list;
	t_file		*last_dir;
	t_file		*last_file;

	curr = *head;
	file_list = NULL;
	dir_list = NULL;
	last_dir = NULL;
	last_file = NULL;
	if (curr->next != NULL)
	{
		while (curr)
		{
			next = curr->next;
			if (S_ISDIR(curr->stat->st_mode))
				lineup_handler(&dir_list, &curr, &last_dir, next);
			else
				lineup_handler(&file_list, &curr, &last_file, next);
		}
		update_head(head, dir_list, file_list, last_file);
	}
}
