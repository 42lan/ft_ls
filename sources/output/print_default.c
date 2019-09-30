/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/30 12:37:16 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int				get_per_row(size_t filename_wmax)
{
	int					per_row;
	struct winsize		terminal;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &terminal);
	per_row = (terminal.ws_col / filename_wmax) - 1;
	return ((per_row < 1) ? 1 : per_row);
}

void					print_default(t_dir *directory)
{
	int					i;
	int					width;
	int					per_row;
	t_file				*file;

	i = -1;
	file = directory->file_head;
	per_row = get_per_row(directory->wmax->filename);
	while (file != NULL)
	{
		width = (file->next && (i != per_row - 1))
				? directory->wmax->filename + 5 : 0;
		print_filename(file, width);
		file = file->next;
		i++;
		if (i == per_row)
		{
			i = 0;
			ft_putchar('\n');
		}
	}
	if (directory->name == NULL || (i > 0 && directory->nb_files > 0))
		ft_putchar('\n');
}
