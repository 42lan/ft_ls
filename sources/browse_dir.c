/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 07:15:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


void				browse_dir(const char *path, struct dirent *dirent, t_dir *current_dir)
{
	DIR				*dp;
	t_file			*file;
	t_file			*list;
	t_list			subdir_list;
	struct passwd	*passwd;
	struct group	*group;

	list = new_file();
	if ((dp = opendir(path)) != NULL)
	{
		initialize_directory(current_dir);
		ft_strcpy(current_dir->name, path);
		while ((dirent = readdir(dp)) != NULL)
		{
			if (is_hidden(dirent->d_name))
				continue ;
			file = new_file();

			stat(dirent->d_name, &file->stat);
			if ((passwd = get_pwstruct(file->stat.st_uid)) == NULL)
				return ;
			if ((group = get_grstruct(file->stat.st_gid)) == NULL)
				return ;
			file->name = dirent->d_name;
			file->namlen = dirent->d_namlen;
			file->ownername = passwd->pw_name;
			file->groupname = group->gr_name;
			++(current_dir->nb_files);
			determine_wmax(dirent, file, current_dir);
			if (is_directory(file->stat.st_mode)) // Checking for subdirectories
			{
				// Forming relative path and saving it
				subdir_list.content = form_path(current_dir->name, dirent->d_name);
				subdir_list.next = NULL;
			}
			add_file(list, file);
		}
	}
	display_default(current_dir, list);
	//display_long(current_dir, list);
	closedir(dp);
}
