/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 18:53:31 by amalsago         ###   ########.fr       */
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

void				nodir_handler(t_file *head)
{
	t_file			*file;
	t_dir			*directory;

	directory = new_directory(NULL);
	while (head && !S_ISDIR(head->stat->st_mode))
	{
		if (S_ISLNK(head->stat->st_mode))
			get_link(head);
		file = new_file(NULL, head->name);
		fill_struct(file);
		determine_wmax(directory->wmax, file);
		append_file(&directory, file);
		directory->nb_files++;
		head = head->next;
	}
	apply_options(directory);
	display(directory);
}

int					ft_ls(t_file *head)
{
	t_file			*file;
	int				one_dir;

	file = head;
	one_dir = check_for_one_dir(file);
	nodir_handler(head);
	while (file)
	{
		if (g_argp[LONG_FORMAT].active && file->name[file->namlen - 1] == '/')
			stat(file->name, file->stat);
		if (S_ISDIR(file->stat->st_mode))
		{
			(one_dir != 1) ? ft_printf("%s:\n", file->name) : 0;
			browse_directory(file->name);
		}
		file = file->next;
		if (file && S_ISDIR(file->stat->st_mode))
			ft_putchar('\n');
	}
	return (1);
}
