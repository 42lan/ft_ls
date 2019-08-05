/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/03 15:09:50 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					display_default(t_dir *current_dir)
{
	struct winsize		w;

	ioctl(0, TIOCGWINSZ, &w);
	while (current_dir->file_head != NULL)
	{
		if (current_dir->file_head->next == NULL)
		{
			display_filename(current_dir->file_head->name, 0);
			ft_putchar('\n');
		}
		else
		{
			//place_cursor(x, y);
			//ft_printf("\033[%d;%dH HELLO", 2, 0);
			display_filename(current_dir->file_head->name, 0);
			ft_putchar('\n');
		}
		current_dir->file_head = current_dir->file_head->next;
	}
}
