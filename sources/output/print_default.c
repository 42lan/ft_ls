/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/07 14:17:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					print_default(t_dir *dir)
{
	struct winsize		w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	while (dir->file_head != NULL)
	{
		print_filename(dir->file_head);
		dir->file_head = dir->file_head->next;
	}
}
