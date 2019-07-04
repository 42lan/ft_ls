/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:09:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 03:25:07 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				insert_end(t_dir *list, t_dir *new_node)
{
	t_dir			*p;

	p = list;
	while (p->next != NULL)
		p = p->next;
	p->next = new_node;
	new_node->next = NULL;
}

void				ft_list_dir(DIR *dp, t_dir *cd, char *entryname)
{
	t_dir			lst_subdir;
	t_dir			subdir;
	struct dirent	*de;
	t_entry			entry;

	entryname = ft_pathjoin(".", entryname);
	while ((de = readdir(dp)) != NULL)
	{
		entry.name = de->d_name;
		stat(ft_pathjoin(entryname, de->d_name), &entry.stat);
		if (entry.stat.st_mode & S_IFDIR) // Если текущий элемент это каталог, то нужно сохранить название каталога, для того, чтобы вызвать на него ft_list_dir() после того, как текущий каталог будет прочтен
		{
			subdir.name = ft_pathjoin(entryname, de->d_name);
			insert_end(&lst_subdir, &subdir);
		}
		if (ft_silen(entry.stat.st_nlink, 10) > cd->nlink_width)
			cd->nlink_width = ft_silen(entry.stat.st_nlink, 10);
		if (ft_silen(entry.stat.st_size, 10) > cd->size_width)
			cd->size_width = ft_silen(entry.stat.st_size, 10);
		stat(entry.name, &entry.stat);
		display_long(&entry);
		//ft_inspect_entry(&entry, subdir.name);
	}
}
