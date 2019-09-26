/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:19:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/26 16:22:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_long(t_dir *directory)
{
	t_file		*file;
	size_t		width;

	file = directory->file_head;
	if (file)
	{
		if (file != NULL)// && S_ISDIR(file->stat->st_mode))
			print_totalblocks(directory->total_blocks);
		while (file != NULL)
		{
			print_mode(file->mode);
			print_nlink(file->stat->st_nlink, directory->nlink_wmax);
			if (g_argp[LONG_WITHOUT_OWNER].active == 0)
				print_ownername(file->ownername, directory->ownername_wmax);
			if (g_argp[LONG_WITHOUT_GROUP].active == 0)
				print_groupname(file->groupname, directory->groupname_wmax);
			if (ft_strequ(directory->name, "/dev") && !(S_ISDIR(file->stat->st_mode)) && !(S_ISLNK(file->stat->st_mode)))
				print_major_minor(directory, file->major, file->minor);
			else
			{
				width = directory->size_wmax;
				if (ft_strequ(directory->name, "/dev") && (S_ISDIR(file->stat->st_mode) || S_ISLNK(file->stat->st_mode)))
					width += 7;
				print_size(file->stat->st_size, width);
			}
			print_mtime(file->stat->st_mtimespec.tv_sec);
			print_filename(file, 0);
			file = file->next;
			ft_printf("\n");
		}
	}
}
