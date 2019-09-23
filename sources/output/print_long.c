/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:19:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/23 13:18:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

void	print_long(t_dir *directory)
{
	if (directory->file_head)
	{
		if (directory->file_head->next != NULL)
			print_totalblocks(directory->total_blocks);
		while (directory->file_head != NULL)
		{
			print_mode(directory->file_head->mode);
			print_nlink(directory->file_head->stat->st_nlink, directory->nlink_wmax);
			print_ownername(directory->file_head->ownername, directory->ownername_wmax);
			print_groupname(directory->file_head->groupname, directory->groupname_wmax);
			if (ft_strequ(directory->name, "/dev") && !(S_ISDIR(directory->file_head->stat->st_mode)))
				print_major_minor(directory, directory->file_head->major, directory->file_head->minor);
			else
				print_size(directory->file_head->stat->st_size,
						(ft_strequ(directory->name, "/dev"))
						 && (S_ISDIR(directory->file_head->stat->st_mode)
						|| S_ISLNK(directory->file_head->stat->st_mode))
						 ? directory->size_wmax + 7 : directory->size_wmax);
			print_mtime(directory->file_head->stat->st_mtimespec.tv_sec);
			print_filename(directory->file_head, 0);
			if (g_argp[INDICATOR].active)
				append_indicator(directory->file_head);
			directory->file_head = directory->file_head->next;
			ft_printf("\n");
		}
	}
}
