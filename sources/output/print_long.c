/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:19:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/08 13:40:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_long(t_dir *dir)
{
	if (dir->file_head)
	{
		if (dir->file_head->next != NULL)
			print_totalblocks(dir->total_blocks);
		while (dir->file_head != NULL)
		{
			print_mode(dir->file_head->mode);
			print_nlink(dir->file_head->stat->st_nlink, dir->nlink_wmax);
			print_ownername(dir->file_head->ownername, dir->ownername_wmax);
			print_groupname(dir->file_head->groupname, dir->groupname_wmax);
			print_size(dir->file_head->stat->st_size, dir->size_wmax);
			print_mtime(dir->file_head->stat->st_mtimespec.tv_sec);
			print_filename(dir->file_head);
			dir->file_head = dir->file_head->next;
		}
	}
}
