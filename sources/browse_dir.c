/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 04:07:41 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file				*new_file()
{
	t_file			*new_file;

	if (!(new_file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new_file->next = NULL;
	return (new_file);
}

t_file				*add_file(t_file *list, t_file *new_file)
{
	t_file			*tmp;

	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_file;
	new_file->next = NULL;
	return (tmp);
}

void				print_files(t_dir *current_dir, t_file *list)
{
	list = list->next;
	while (list->next != NULL)
	{
		display_mode(list->stat.st_mode);
		display_nlink(list->stat.st_nlink, current_dir->nlink_wmax);
		display_ownername(list->ownername, 0);
		display_groupname(list->groupname, 0);
		display_size(list->stat.st_size, current_dir->size_wmax);
		display_mtim(list->stat.st_mtimespec.tv_sec);
		display_filename(list->name);
		ft_putstr("");
		list = list->next;
	}
}

size_t				list_length(t_file *list)
{
	int				length;

	length = 0;
	if (list->next == NULL)
		return (0);
	while (list != NULL)
	{
		++length;
		list = list->next;
	}
	return (length);
}

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

			file->name = dirent->d_name;
			file->namlen = dirent->d_namlen;
			++(current_dir->nb_files);
			stat(dirent->d_name, &file->stat);
			determine_wmax(dirent, file, current_dir);

			if ((passwd = get_pwstruct(file->stat.st_uid)) == NULL)
				return ;
			if ((group = get_grstruct(file->stat.st_gid)) == NULL)
				return ;

			file->ownername = passwd->pw_name;
			file->groupname = group->gr_name;

			if (is_directory(file->stat.st_mode)) // Checking for subdirectories
			{
				// Forming relative path and saving it
				subdir_list.content = form_path(current_dir->name, dirent->d_name);
				subdir_list.next = NULL;
			}
			//add_file(list, file);
		}
	}
//	print_files(current_dir, list);
	closedir(dp);
}
