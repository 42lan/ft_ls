/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/30 08:53:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					print_default(t_dir *directory)
{
	int					i;
	int					width;
	int					per_row;
	struct winsize		terminal;
	t_file				*file;

	i = -1;
	file = directory->file_head;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &terminal);
	per_row = (terminal.ws_col / directory->wmax->filename) - 1;
	if (per_row < 1)
		per_row = 1;
	while (file != NULL)
	{
		width = (file->next && (i != per_row - 1)) ? directory->wmax->filename + 5 : 0;
		print_filename(file, width);
		file = file->next;
		i++;
		if (i == per_row)
		{
			i = 0;
			ft_putchar('\n');
		}
	}
	(i != 0) ? ft_putchar('\n') : 0;
}
