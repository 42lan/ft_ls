/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:18:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/07 13:31:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_filename(t_file *file)
{
	char		*target;
	int			target_len;

	if (g_argp[LONG_FORMAT].active)
	{
		if (S_ISLNK(file->stat->st_mode))
		{
			if (file->stat->st_size == 0)
				target_len = PATH_MAX;
			else
				target_len = file->stat->st_size;
			target = ft_strnew(target_len);
			readlink(file->relpath, target, target_len);
			ft_printf(" %s -> %s\n", file->name, target);
		}
		else
			ft_printf(" %s\n", file->name);
	}
	else
		ft_printf("%s\n", file->name);
}
