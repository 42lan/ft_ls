/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:37:26 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/22 12:36:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					check_subdir(t_file *file, struct dirent *dirent, t_dir *current_dir)
{
	char			*path = NULL;

	if (is_directory(file->stat.st_mode))
	{
		// Forming a relative path for a subdirectory
		path = form_path(current_dir->name, dirent->d_name);
		// If sdir_head is empty, so the first node of a link list is the first readed subdir
		if (current_dir->sdir_head == NULL)
			current_dir->sdir_head = ft_lstnew(path, ft_strlen(path));
		// Else, sdir_head has a node, so append linked list with new subdir
		else
			ft_lstadd_end(&current_dir->sdir_head, ft_lstnew(path, ft_strlen(path)));
		return (1);
	}
	return (0);
}
