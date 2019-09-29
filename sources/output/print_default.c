/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 19:37:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					print_default(t_dir *directory)
{
	int					i;
	int					per_row;
	t_file				*file;
	struct winsize		terminal;

	i = -1;
	file = directory->file_head;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &terminal);
	per_row = (terminal.ws_col / directory->wmax->filename) - 1;
	if (per_row < 1)
		per_row = 1;
	while (file != NULL)
	{
		print_filename(file, (directory->nb_files != 1 && ++i == per_row - 1)
								? file->namlen : directory->wmax->filename + 5);
		file = file->next;
		if (i == per_row)
		{
			i = 0;
			ft_putchar('\n');
		}
	}
	(i != 0) ? ft_putchar('\n') : 0;
}
