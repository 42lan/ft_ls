/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:37:26 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/05 11:33:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_subdir(t_file *file, t_dir *current_dir)
{
	t_list	*new_sdir;

	if (is_directory(file->stat->st_mode))
	{
		// If sdir_head is empty, so the first node of a link list is the first readed subdir
		if (current_dir->sdir_head == NULL)
			current_dir->sdir_head = ft_lstnew(file->relpath, ft_strlen(file->relpath) + 1); // abaisago: +1 pour '\0'
		// Else, sdir_head has a node, so append linked list with new subdir
		else
		{
			new_sdir = ft_lstnew(file->relpath, ft_strlen(file->relpath) + 1); // abaisago: +1 pour '\0'
			ft_lstadd_end(&current_dir->sdir_head, new_sdir);
		}
		return (1);
	}
	return (0);
}
