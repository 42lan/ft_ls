/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/21 15:50:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

int					ft_ls(t_file *head)
{
	t_file			*file;

	file = head;
	while (file)
	{
		if (g_argp[LONG_FORMAT].active && file->name[file->namlen - 1] == '/')
			stat(file->name, file->stat);
		if (S_ISDIR(file->stat->st_mode))
			browse_directory(file->name);
		else
		{
			if (S_ISLNK(file->stat->st_mode))
				get_link(file);
			browse_file(file->name, file);
		}
		file = file->next;
	}
	return (1);
}
