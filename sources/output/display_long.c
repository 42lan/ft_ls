/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:19:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/04 18:12:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_long(t_dir *dir)
{
	if (dir->file_head)
	{
		if (dir->file_head->next != NULL)
			display_total(dir->total_blocks);
		while (dir->file_head != NULL)
		{
			display_mode(dir->file_head->stat->st_mode);
			//display_acl();
			display_nlink(dir->file_head->stat->st_nlink, dir->nlink_wmax);
			display_ownername(dir->file_head->ownername, dir->ownername_wmax);
			display_groupname(dir->file_head->groupname, dir->groupname_wmax);
			display_size(dir->file_head->stat->st_size, dir->size_wmax);
			display_mtim(dir->file_head->stat->st_mtimespec.tv_sec);
			display_filename(dir->file_head);
			dir->file_head = dir->file_head->next;
		}
	}
}
