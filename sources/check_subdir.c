/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_subdir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:37:26 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/02 16:50:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			check_subdir(t_file *file, t_dir *current_dir)
{
	if (S_ISDIR(file->stat->st_mode))
	{
		//file = new_file(file->relpath, NULL);
		if (current_dir->sdir_head == NULL)
			current_dir->sdir_head = file;
		else
		{
			file->next = current_dir->sdir_head;
			current_dir->sdir_head = file;
		}
		return (1);
	}
	return (0);
}
