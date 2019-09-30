/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeup_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:01:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/30 17:39:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_directory(t_dir *directory)
{
	t_file		*file;
	t_file		*next;
	if (directory == NULL)
		return ;
	file = directory->file_head;
	while (file)
	{
		next = file->next;
		free_file(file);
		free(&file);
		file = next;
	}

}

void	free_file(t_file *file)
{
	ft_strdel(&file->name);
	ft_strdel(&file->relpath);
	ft_strdel(&file->mode);
}
