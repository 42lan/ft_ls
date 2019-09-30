/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/30 10:57:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

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
		head = head->next;
	}
	apply_options(directory);
	display(directory);
}

static void		directories_handler(t_file *head, size_t nb_files)
{
	while (head)
	{
		if (S_ISDIR(head->stat->st_mode))
		{
			(nb_files > 1) ? ft_printf("%s:\n", head->name) : 0;
			browse_directory(head->name);
		}
		head = head->next;
		if (head && S_ISDIR(head->stat->st_mode))
			ft_putchar('\n');
	}
}

int				ft_ls(t_dir *head)
{
	t_file		*file_list;

	if (head == NULL || head->file_head == NULL)
		return (0);
	file_list = head->file_head;
	if (!S_ISDIR(file_list->stat->st_mode))
		nondirtypes_handler(file_list);
	if (file_list)
		directories_handler(file_list, head->nb_files);
	return (1);
}
