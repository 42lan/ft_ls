/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/23 14:20:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

static int			check_for_one_dir(t_file *head)
{
	t_file			*tmp;
	int				one_dir;

	tmp = head;
	one_dir = 1;
	while (tmp && one_dir == 1)
	{
		if (S_ISDIR(tmp->stat->st_mode))
			if (tmp->next && S_ISDIR(tmp->next->stat->st_mode))
				one_dir = 0;
		tmp = tmp->next;
	}
	return (one_dir);
}

int					ft_ls(t_file *head)
{
	int				one_dir;
	t_file			*file;

	file = head;
	one_dir = check_for_one_dir(file);
	while (file)
	{
		if (g_argp[LONG_FORMAT].active && file->name[file->namlen - 1] == '/')
			stat(file->name, file->stat);
		if (S_ISDIR(file->stat->st_mode))
		{
			(one_dir != 1) ? ft_printf("%s:\n", file->name) : 0;
			browse_directory(file->name);
		}
		else
		{
			if (S_ISLNK(file->stat->st_mode))
				get_link(file);
			browse_file(file->name);
		}
		file = file->next;
		if (file && S_ISDIR(file->stat->st_mode))
			ft_putchar('\n');
	}
	return (1);
}
