/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 21:42:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/13 09:42:42 by amalsago         ###   ########.fr       */
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
		ft_strcpy(current_dir->name, path);
		current_dir->nb_files = 0;
		current_dir->namlen_wmax = 0;
		while ((dirent = readdir(dp)) != NULL)
		{
			if (is_hidden(dirent->d_name))
				continue ;
			file = new_file();
			if (dirent->d_namlen > current_dir->namlen_wmax)
				current_dir->namlen_wmax = dirent->d_namlen;
			++(current_dir->nb_files);

			file->name = dirent->d_name;
			file->namlen = dirent->d_namlen;
			if (file->namlen > current_dir->namlen_wmax)
				current_dir->namlen_wmax = file->namlen;

			if (stat(dirent->d_name, &file->stat) != 0)
				ft_printf("-----------------Stat error--------------: %s\n", strerror(errno));

			if (ft_uilen(file->stat.st_nlink, 10) > current_dir->nlink_wmax)
				current_dir->nlink_wmax = ft_uilen(file->stat.st_nlink, 10);
			if (ft_uilen(file->stat.st_size, 10) > current_dir->size_wmax)
				current_dir->size_wmax = ft_uilen(file->stat.st_size, 10);

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
