/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/22 12:52:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_list(t_list *list)
{
	while (list != NULL)
	{
		if (list->next == NULL)
			ft_printf("%s -> NULL\n", list->content);
		else
		{
			//ft_printf("%s -> ", list->content);
			write(1, list->content, list->content_size);
			write(1, " -> ", 4);
		}
		list = list->next;
	}
}

t_dir				*browse_dir(const char *path)
{
	DIR				*dp;
	struct dirent	*dirent;
	t_dir			*current_dir;
	t_file			*file;

	if ((dp = opendir(path)) == NULL)					// Trying to open given path
		return (NULL);
	current_dir = initialize_directory();
	current_dir->name = ft_strdup(path);
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
		if (check_subdir(file, dirent, current_dir))		// Checking if actual file is a directory
			print_list(current_dir->sdir_head);
		push_end(current_dir->file_head, file);			// Appending new node to file list
	}
	closedir(dp);
	//print_list(current_dir->sdir_head);
	return (current_dir);
}
