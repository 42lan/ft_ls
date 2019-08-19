/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/19 17:22:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					display_default(t_dir *dir)
{
	struct winsize		w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	while (dir->file_head != NULL)
	{
		//place_cursor(x, y);
		if (dir->file_head->next == NULL)
			display_filename(dir->file_head, 0);
		else
			display_filename(dir->file_head, 0);
		dir->file_head = dir->file_head->next;
	}
}
