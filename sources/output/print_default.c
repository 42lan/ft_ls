/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/23 13:21:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp			g_argp[];

void					print_default(t_dir *directory)
{
	size_t				i;
	size_t				per_row;
	size_t				per_col;
	struct winsize		terminal;
	int					width;

	i = 0;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &terminal);
	per_row = (terminal.ws_col / directory->filename_wmax) - 1;
	per_col = (directory->nb_files / per_row) + 1;
	while (directory->file_head != NULL)
	{
		width = (directory->file_head->next) ? directory->filename_wmax + 1 : 0;
		print_filename(directory->file_head, width);
		if (g_argp[INDICATOR].active)
			append_indicator(directory->file_head);
		directory->file_head = directory->file_head->next;
		i++;
		if (i == per_row)
		{
			i = 0;
			ft_putchar('\n');
		}
		/*
		if (i == per_col)
		{
			i = 0;
			ft_putendl("\n-----");
		}
		else
			ft_putchar('\n');
		*/
	}
	ft_putchar('\n');
}
