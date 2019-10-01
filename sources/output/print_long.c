/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:19:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 15:34:41 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_major_minor_or_size(t_dir *directory, t_file *file)
{
	int			width;
	mode_t		st_mode;

	if (is_dev_dir(directory->name) && isnt_dir_and_lnk(file))
		print_major_minor(directory->wmax, file->major, file->minor);
	else
	{
		width = directory->wmax.size;
		st_mode = file->stat.st_mode;
		print_size(file->stat.st_size, ((is_dev_dir(directory->name))
					&& (S_ISDIR(st_mode) || S_ISLNK(st_mode)))
				? width + 7 : width);
	}
}

void			print_long(t_dir *directory)
{
	t_file		*file;
	t_wmax		wmax;

	file = directory->file_head;
	wmax = directory->wmax;
	if (file)
	{
		if (directory->name && file)
			print_totalblocks(directory->total_blocks);
		while (file != NULL)
		{
			print_mode(file->mode);
			print_nlink(file->stat.st_nlink, wmax.nlink);
			print_ownername(file->ownername, wmax.ownername);
			print_groupname(file->groupname, wmax.groupname);
			print_major_minor_or_size(directory, file);
			print_mtime(file->stat.st_mtimespec.tv_sec);
			print_filename(file, 0);
			file = file->next;
			ft_printf("\n");
		}
	}
}
