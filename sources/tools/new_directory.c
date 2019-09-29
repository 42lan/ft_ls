/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_directory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:39:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 13:41:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_wmax	*new_wmax(void)
{
	t_wmax		*wmax;

	if (!(wmax = (t_wmax *)ft_memalloc(sizeof(t_wmax))))
		return (NULL);
	wmax->filename = 1;
	wmax->ownername = 0;
	wmax->groupname = 0;
	wmax->size = 0;
	wmax->major = 0;
	wmax->minor = 0;
	wmax->nlink = 0;
	return (wmax);
}

t_dir			*new_directory(const char *name)
{
	t_dir		*directory;

	if (!(directory = (t_dir *)ft_memalloc(sizeof(t_dir))))
		return (NULL);
	directory->name = (name != NULL) ? ft_strdup(name) : NULL;
	directory->ownername = NULL;
	directory->groupname = NULL;
	directory->total_blocks = 0;
	directory->nb_files = 0;
	directory->wmax = new_wmax();
	directory->subdir_head = NULL;
	directory->file_head = NULL;
	return (directory);
}
