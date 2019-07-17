/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:37:26 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/17 15:09:56 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_sdir		 *push_end_sdir(t_sdir *head, t_sdir *sdir)
{
	t_sdir	*tmp;

	tmp = head;
	if (head == NULL)
		head = sdir;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = sdir;
		sdir->next = NULL;
	}
	return (head);
}

int		check_subdir(t_file *file, struct dirent *dirent, t_dir *current_dir, t_sdir *sdir)
{
	if (is_directory(file->stat.st_mode)) // Checking for subdirectories
	{
		if (current_dir->sdir_head == NULL)
			current_dir->sdir_head = sdir;
		sdir->path = form_path(current_dir->name, dirent->d_name); // Forming relative path and saving it
		sdir->next = NULL;
		push_end_sdir(current_dir->sdir_head, sdir);
		return (1);
	}
	return (0);
}
