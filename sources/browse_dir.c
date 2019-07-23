/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/23 17:33:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir				*browse_dir(const char *path)
{
	DIR				*dp;
	struct dirent	*dirent;
	t_dir			*current_dir;
	t_file			*file;

	if ((dp = opendir(path)) == NULL)					// Trying to open given path
	{
		ft_printf("ft_ls: %s: %s\n", path, strerror(errno));
		return (NULL);
	}
	current_dir = initialize_directory();
	current_dir->name = ft_strdup(path);
	while ((dirent = readdir(dp)) != NULL)				// Reading directory entry by entry
	{
		++(current_dir->nb_files);						// Counting number of files including hidden + . and ..
		if (is_hidden(dirent->d_name))					// Checking for hidden files
			continue ;									// Skipping hiddent files
		file = new_file();								// !!! Need to check allocation
		file->dirname = ft_strdup(path);
		if (current_dir->file_head == NULL)				// Checking if file_head pointer is NULL
			current_dir->file_head = file;				// If file_head pointer pointed no NULL so now it points to first file
		fill_file_struct(file, dirent);					// Filling file structure
		determine_wmax(dirent, file, current_dir);
		check_subdir(file, dirent, current_dir);		// Checking if actual file is a directory
		push_end(current_dir->file_head, file);			// Appending new node to file list
		current_dir->total_blocks++;
	}
	//ft_lstprint(current_dir->sdir_head);
	display_long(current_dir);
	if (current_dir->sdir_head != NULL)
		recursive_browse(current_dir->sdir_head);




	/***** FREEING ALLOCATED MEMORY *****/
	free(current_dir->name);	current_dir->name = NULL;
	free(current_dir);			current_dir = NULL;
	free(file->dirname);		file->dirname = NULL;
	free(file);					file = NULL;
	closedir(dp);
	return (current_dir);
}
