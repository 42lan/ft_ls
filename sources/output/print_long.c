/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:19:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/21 17:50:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

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
			if (ft_strstr(directory->name, "/dev") && !(S_ISDIR(directory->file_head->stat->st_mode)))
				print_major_minor(directory, directory->file_head->major, directory->file_head->minor);
			else
				print_size(directory->file_head->stat->st_size, directory->size_wmax);
			print_mtime(directory->file_head->stat->st_mtimespec.tv_sec);
			print_filename(directory->file_head, 0);
			directory->file_head = directory->file_head->next;
			ft_printf("\n");
		}
	}
}
