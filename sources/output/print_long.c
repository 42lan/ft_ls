/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:19:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/23 13:39:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_long(t_dir *directory)
{
	t_file		*file;

	file = directory->file_head;
	if (file)
	{
		if (file->next != NULL)
			print_totalblocks(directory->total_blocks);
		while (file != NULL)
		{
			print_mode(file->mode);
			print_nlink(file->stat->st_nlink, directory->nlink_wmax);
			print_ownername(file->ownername, directory->ownername_wmax);
			print_groupname(file->groupname, directory->groupname_wmax);
			if (ft_strequ(directory->name, "/dev") && !(S_ISDIR(file->stat->st_mode)))
				print_major_minor(directory, file->major, file->minor);
			else
				print_size(file->stat->st_size,
						(ft_strequ(directory->name, "/dev"))
						&& ((S_ISDIR(file->stat->st_mode)
							|| S_ISLNK(file->stat->st_mode)))
						? directory->size_wmax + 7 : directory->size_wmax);
			print_mtime(file->stat->st_mtimespec.tv_sec);
			print_filename(file, 0);
			if (g_argp[INDICATOR].active)
				append_indicator(file);
			file = file->next;
			ft_printf("\n");
		}
	}
}
