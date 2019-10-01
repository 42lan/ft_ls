/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_directory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 13:32:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

static void			append_subdir(t_dir **dir, t_file *file, const char *path)
{
	t_file			*subdir;

	subdir = new_file(path, file->name);
	if ((*dir)->subdir_head == NULL)
		(*dir)->subdir_head = subdir;
	else
	{
		subdir->next = (*dir)->subdir_head;
		(*dir)->subdir_head = subdir;
	}
}

static void			recursive_browse(t_file *subdir_head)
{
	while (subdir_head != NULL)
	{
		ft_printf("\n%s:\n", subdir_head->relpath);
		browse_directory(subdir_head->relpath);
		subdir_head = subdir_head->next;
	}
}

static void			loop_through(DIR *dp, t_dir *directory, const char *path)
{
	t_file			*file;
	struct dirent	*dirent;

	while ((dirent = readdir(dp)) != NULL)
	{
		if (need_to_skip(dirent->d_name))
			continue ;
		file = new_file(path, dirent->d_name);
		fill_struct(file);
		determine_wmax(directory->wmax, file);
		if (!(ft_strequ(file->name, ".") || ft_strequ(file->name, "..")))
			if (S_ISDIR(file->stat.st_mode))
				append_subdir(&directory, file, path);
		append_file(&directory, file);
		directory->total_blocks += file->stat.st_blocks;
	}
}

void				browse_directory(const char *path)
{
	DIR				*dp;
	char			*basename;
	t_dir			*directory;

	if ((dp = opendir(path)) == NULL)
	{
		basename = ft_strrchr(path, '/');
		print_ft_ls_error((basename == NULL) ? path : basename + 1, errno);
		return ;
	}
	directory = new_directory(path);
	loop_through(dp, directory, path);
	apply_options(directory);
	display(directory);
	if (g_argp[RECURSIVE].active && directory->subdir_head != NULL)
		recursive_browse(directory->subdir_head);
	closedir(dp);
}
