/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/17 17:37:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir				*browse_dir(const char *path)
{
	DIR				*dp;
	struct dirent	*dirent;
	t_dir			*current_dir;
	t_file			*file;
	t_sdir			*sdir;

	if ((dp = opendir(path)) == NULL)					// Trying to open given path
		return (NULL);
	current_dir = initialize_directory();
	current_dir->name = ft_strdup(path);
	sdir = (t_sdir *)malloc(sizeof(t_sdir));			// Allocation memory for subdirectories. Need to allocate
	while ((dirent = readdir(dp)) != NULL)				// Reading directory entry by entry
	{
		++(current_dir->nb_files);						// Counting number of files including hidden + . and ..
		if (is_hidden(dirent->d_name))					// Checking for hidden files
			continue ;									// Skipping hiddent files
		file = new_file();								// !!! Need to check allocation
		if (current_dir->file_head == NULL)				// Checking if file_head pointer is NULL
			current_dir->file_head = file;				// If file_head pointer pointed no NULL so now it points to first file
		fill_file_struct(file, dirent);					// Filling file structure
		determine_wmax(dirent, file, current_dir);
		check_subdir(file, dirent, current_dir, sdir);
		push_end(current_dir->file_head, file);			// Appending new node to file list
	}
	closedir(dp);
	/*
	while (current_dir->sdir_head != NULL)
	{
		browse_dir(current_dir->sdir_head->path, current_dir);
		current_dir->sdir_head = current_dir->sdir_head->next;
	}
	*/
	return (current_dir);
}
