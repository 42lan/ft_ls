/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:29:55 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/01 19:30:01 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*new_file(const char *name, const char *path)
{
	t_file	*new_file;

	if (!(new_file = (t_file *)ft_memalloc(sizeof(t_file))))
		return (NULL);
	new_file->name = ft_strdup(name);
	new_file->relpath = (path == NULL) ? NULL : form_relpath(path, name);
	new_file->namlen = ft_strlen(name);
	new_file->stat = NULL;
	new_file->ownername = NULL;
	new_file->groupname = NULL;
	new_file->next = NULL;
	return (new_file);
}
