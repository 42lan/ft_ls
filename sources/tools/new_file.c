/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:29:55 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/22 11:10:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*new_file(const char *path, const char *name)
{
	t_file	*file;

	if (!(file = (t_file *)ft_memalloc(sizeof(t_file))))
		return (NULL);
	file->name = ft_strdup(name);
	file->relpath = (path == NULL) ? NULL : form_relpath(path, name);
	file->namlen = ft_strlen(name);
	file->targetlen = 0;
	file->stat = NULL;
	file->ownername = NULL;
	file->groupname = NULL;
	file->mode = NULL;
	file->next = NULL;
	return (file);
}
