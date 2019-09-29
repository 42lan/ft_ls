/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 08:27:01 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

static int		check_for_one_dir(t_file *head)
{
	t_file		*tmp;
	int			one_dir;

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

static void		nondirtypes_handler(t_file *head)
{
	t_file		*file;
	t_dir		*directory;

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

static void		directories_handler(t_file *head)
{
	int			one_dir;

	one_dir = check_for_one_dir(head);
	while (head)
	{
		if (g_argp[LONG_FORMAT].active && head->name[head->namlen - 1] == '/')
			stat(head->name, head->stat);
		if (S_ISDIR(head->stat->st_mode))
		{
			(one_dir != 1) ? ft_printf("%s:\n", head->name) : 0;
			browse_directory(head->name);
		}
		head = head->next;
		if (head && S_ISDIR(head->stat->st_mode))
			ft_putchar('\n');
	}
}

int				ft_ls(t_file *head)
{
	if (!head)
		return (0);
	if (!S_ISDIR(head->stat->st_mode))
		nondirtypes_handler(head);
	if (head)
		directories_handler(head);
	return (1);
}
