/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeup_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:01:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 21:05:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		remove_handler(t_file *file)
{
	t_file		*next;

	while (file)
	{
		next = file->next;
		remove_file(file);
		file = next;
	}
}

void			remove_directory(t_dir *directory)
{
	if (directory == NULL)
		return ;
	if (directory->subdir_head)
		remove_handler(directory->subdir_head);
	if (directory->file_head)
		remove_handler(directory->file_head);
	ft_memdel((void **)&directory->name);
	ft_memdel((void **)&directory);
}

void			remove_file(t_file *file)
{
	ft_memdel((void **)&file->name);
	ft_memdel((void **)&file->relpath);
	ft_memdel((void **)&file);
}
