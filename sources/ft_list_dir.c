/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:09:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 07:21:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				insert_end(t_list *sdl, t_list *new_node)
{
	t_list			*p;

	p = sdl;
	while (p->next != NULL)
		p = p->next;
	p->next = new_node;
	new_node->next = NULL;
}

void				ft_list_dir(DIR *dp, t_dir *cd, char *entryname, t_list *sdl)
{
	t_list			subdir;
	struct dirent	*de;
	t_entry			entry;

	cd->nlink_width = 0;
	cd->size_width = 0;
	cd->ownername_width = 0;
	entryname = ft_pathjoin(".", entryname);
	while ((de = readdir(dp)) != NULL)
	{
		entry.name = de->d_name;
		stat(ft_pathjoin(entryname, de->d_name), &entry.stat);
		if (entry.stat.st_mode & S_IFDIR) // Если текущий элемент это каталог, то нужно сохранить название каталога, для того, чтобы вызвать на него ft_list_dir() после того, как текущий каталог будет прочтен
		{
			sdl->content = ft_pathjoin(entryname, de->d_name);
			(void)subdir;
			//insert_end(sdl, &subdir);
		}
		if (ft_silen(entry.stat.st_nlink, 10) > cd->nlink_width)
			cd->nlink_width = ft_silen(entry.stat.st_nlink, 10);
		if (ft_silen(entry.stat.st_size, 10) > cd->size_width)
			cd->size_width = ft_silen(entry.stat.st_size, 10);

		stat(entry.name, &entry.stat);

		get_pwstruct(entry.stat.st_uid, &entry.passwd);
		cd->ownernamelen = ft_strlen(entry.passwd->pw_name);
		if (cd->ownernamelen > cd->ownername_width)
			cd->ownername_width = cd->ownernamelen;

		get_grstruct(entry.stat.st_gid, &entry.group);
		cd->groupnamelen = ft_strlen(entry.passwd->pw_name);
		if (cd->groupnamelen > cd->ownername_width)
			cd->ownername_width = cd->groupnamelen;
		// Вызов display_long не должен быть здесь
		//display_long(cd, &entry);
	}
	/*
	closedir(dp);
	dp = opendir(entryname);
	while ((de = readdir(dp)) != NULL)
	{
		entry.name = de->d_name;
		stat(ft_pathjoin(entryname, de->d_name), &entry.stat);
		stat(entry.name, &entry.stat);
		get_pwstruct(entry.stat.st_uid, &entry.passwd);
		get_grstruct(entry.stat.st_gid, &entry.group);
		display_long(cd, &entry);
	}
	*/
}
