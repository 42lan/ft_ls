/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/02 21:34:47 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

static void			loop_through_dir(DIR *dp, t_dir *current_dir, const char *path)
{
	t_file			*file;
	struct dirent	*dirent;

	while ((dirent = readdir(dp)) != NULL)					// Reading directory entry by entry
	{
		++(current_dir->nb_files);							// Counting number of files including hidden + . and ..
		if (is_hidden(dirent->d_name) && g_argp[1].active == 0)						// Checking for hidden files
			continue ;										// Skipping hiddent files
		file = new_file();									// !!! Need to check allocation
		if (current_dir->file_head == NULL)					// Checking if file_head pointer is NULL
			current_dir->file_head = file;					// If file_head pointer pointed no NULL so now it points to first file
		file->relpath = form_relpath(path, dirent->d_name);	// Forming relative path to call get_stat()
		file->stat = get_stat(file->relpath);				// Getting stat about file
		fill_file_struct(file, dirent);						// Filling file structure
		determine_wmax(dirent, file, current_dir);
		if (!(ft_strequ(file->name, ".") || ft_strequ(file->name, ".."))) // To avoid . and .. while recursion
			check_subdir(file, current_dir);					// Checking if actual file is a directory
		push_end(current_dir->file_head, file);				// Appending new node to file list
		current_dir->total_blocks += file->stat->st_blocks;
	}
}

t_dir				*browse_dir(const char *path)
{
	DIR				*dp;
	t_dir			*current_dir;

	if ((dp = opendir(path)) == NULL)						// Trying to open given path
	{
		ft_printf("ft_ls: %s: %s\n", path, strerror(errno));
		return (NULL);
	}
	current_dir = initialize_directory();
	current_dir->name = ft_strdup(path);
	loop_through_dir(dp, current_dir, path);				// Callig function to llop through directory
	display(current_dir);
	if (g_argp[2].active == 1 && current_dir->sdir_head != NULL)
		recursive_browse(current_dir->sdir_head);
	closedir(dp);
	return (current_dir);
}
