/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/25 12:38:11 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					print_default(t_dir *directory)
{
	int					i;
	int					per_row;
	int					per_col;
	struct winsize		terminal;

	i = 0;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &terminal);
	per_row = (terminal.ws_col / directory->filename_wmax) - 1;
	if (per_row < 1)
		per_row = 1;
	per_col = (directory->nb_files / per_row) + 1;
	while (directory->file_head != NULL)
	{
		print_filename(directory->file_head, (directory->file_head->next
					&& (i != per_row - 1)) ? directory->filename_wmax + 5 : 0);
		directory->file_head = directory->file_head->next;
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
