/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:18:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/04 10:20:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			display_filename(t_file *file, int width)
{
	char		*target;
	int			target_len;

	if (g_argp[LONG_FORMAT].active && S_ISLNK(file->stat->st_mode))
	{
		target_len = (file->stat->st_size == 0) ? PATH_MAX : file->stat->st_size;
		target = ft_strnew(target_len);
		readlink(file->relpath, target, target_len);
		ft_printf("%*s -> %s\n", file->namlen + width, file->name, target);
	}
	else
		ft_printf("%*s\n", width, file->name);
}
