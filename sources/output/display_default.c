/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/06 09:56:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					display_default(t_dir *current_dir)
{
	struct winsize		w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	while (current_dir->file_head != NULL)
	{
		//place_cursor(x, y);
		if (current_dir->file_head->next == NULL)
		{
			display_filename(current_dir->file_head->name, 0);
			ft_putchar('\n');
		}
		else
		{
			display_filename(current_dir->file_head->name, 0);
			ft_putchar('\n');
		}
		current_dir->file_head = current_dir->file_head->next;
	}
}
