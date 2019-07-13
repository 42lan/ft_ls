/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:09:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/09 23:34:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				insert_end(t_list *subdir_list, t_list *new_node)
{
	t_list			*p;

	p = subdir_list;
	while (p->next != NULL)
		p = p->next;
	p->next = new_node;
	new_node->next = NULL;
}

void				list_dir(DIR *dp, t_dir *cd, char *entryname, t_list *subdir_list, int *options)
{
	t_list			subdir;
	struct dirent	*de;
	t_file			file;

	cd->namlen_max = 0;
	cd->nlink_width = 0;
	cd->size_width = 0;
	cd->ownername_width = 0;
	while ((de = readdir(dp)) != NULL)
	{
		file.name = de->d_name;
		if (*options & 0x01) // If -l was specified
		{
			stat(ft_pathjoin(entryname, de->d_name), &file.stat);
			if (file.stat.st_mode & S_IFDIR) // Если текущий элемент это каталог, то нужно сохранить название каталога, для того, чтобы вызвать на него ft_list_dir() после того, как текущий каталог будет прочтен
			{
				subdir_list->content = ft_pathjoin(entryname, de->d_name);
				(void)subdir;
				//insert_end(subdir_list, &subdir);
			}
			if (ft_silen(file.stat.st_nlink, 10) > cd->nlink_width)
				cd->nlink_width = ft_silen(file.stat.st_nlink, 10);
			if (ft_silen(file.stat.st_size, 10) > cd->size_width)
				cd->size_width = ft_silen(file.stat.st_size, 10);
			stat(file.name, &file.stat);
			get_pwstruct(file.stat.st_uid, &file.passwd);
			cd->ownernamelen = ft_strlen(file.passwd->pw_name);
			if (cd->ownernamelen > cd->ownername_width)
				cd->ownername_width = cd->ownernamelen;

			get_grstruct(file.stat.st_gid, &file.group);
			cd->groupnamelen = ft_strlen(file.passwd->pw_name);
			if (cd->groupnamelen > cd->ownername_width)
				cd->ownername_width = cd->groupnamelen;
			//display_long(cd, &entry);
		}
	}
}
