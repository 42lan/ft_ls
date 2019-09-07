/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/07 19:56:53 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

static void			recursive_browse(t_file *subdir_head)
{
	while (subdir_head != NULL)
	{
		ft_putchar('\n');;
		ft_printf("%s :\n", subdir_head->relpath);
		browse_dir(subdir_head->relpath);
		subdir_head = subdir_head->next;
	}
}

void				append_subdir(t_dir **dir, t_file *file, const char *path)
{
	t_file			*subdir;

	subdir = new_file(file->name, path);
	if ((*dir)->subdir_head == NULL)
		(*dir)->subdir_head = subdir;
	else
	{
		subdir->next = (*dir)->subdir_head;
		(*dir)->subdir_head = subdir;
	}
}

void				append_file(t_dir **dir, t_file *file)
{
	if ((*dir)->file_head == NULL)
		(*dir)->file_head = file;
	else
	{
		file->next = (*dir)->file_head;
		(*dir)->file_head = file;
	}
}

static void			loop_through_dir(DIR *dp, t_dir *directory, const char *path)
{
	t_file			*file;
	struct dirent	*dirent;

	while ((dirent = readdir(dp)) != NULL)
	{
		if (g_argp[SHOW_HIDDEN].active == 0 && is_hidden(dirent->d_name))
			continue ;
		++(directory->nb_files);
		file = new_file(dirent->d_name, path);
		get_stat(file->relpath, file);		
		fill_struct(file, dirent);
		determine_wmax(dirent, file, directory);
		if (!(ft_strequ(file->name, ".") || ft_strequ(file->name, "..")))
			if (S_ISDIR(file->stat->st_mode))
				append_subdir(&directory, file, path);
		append_file(&directory, file);
		directory->total_blocks += file->stat->st_blocks;
	}
}

void				browse_dir(const char *path)
{
	DIR				*dp;
	t_dir			*directory;

	if ((dp = opendir(path)) == NULL)
		ft_printf("ft_ls: %s: %s\n", path, strerror(errno));
	directory = new_directory(path);
	loop_through_dir(dp, directory, path);
	ft_mergesort(&directory->file_head, &name_cmp);
	if (g_argp[REVERSE_ORDER].active == 1)
		reverse_files(&directory->file_head);
	if (g_argp[MTIME_SORT].active == 1)
	{
		ft_mergesort(&directory->file_head, &mtime_cmp);
		reverse_files(&directory->file_head);
	}
	display(directory);
	if (g_argp[RECURSIVE].active == 1 && directory->subdir_head != NULL)
	{
		ft_mergesort(&directory->subdir_head, &name_cmp);
		recursive_browse(directory->subdir_head);
	}
	closedir(dp);
}
