/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 10:28:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					print_default(t_dir *directory)
{
	int					i;
	int					per_row;
	int					per_col;
	t_file				*file;
	struct winsize		terminal;

	i = 0;
	file = directory->file_head;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &terminal);
	per_row = (terminal.ws_col / directory->wmax->filename) - 1;
	if (per_row < 1)
		per_row = 1;
	per_col = (directory->nb_files / per_row) + 1;
	while (file != NULL)
	{
		print_filename(file, (i == per_row - 1) ? file->namlen : directory->wmax->filename + 5);
		file = file->next;
		i++;
		if (i == per_row)
		{
			i = 0;
			ft_putchar('\n');
		}
	}
	if (i != 0)
		ft_putchar('\n');
}
