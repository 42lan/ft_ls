/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:18:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 13:34:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			putoffset(int width)
{
	while (width-- > 0)
		write(1, " ", 1);
}

void			print_filename(t_file *file, int width)
{
	if (g_argp[LONG_FORMAT].active)
	{
		if (S_ISLNK(file->stat.st_mode))
		{
			ft_printf(" %s", file->name, file->target);
			append_indicator(file);
			ft_printf(" -> %s", file->target);
		}
		else
		{
			ft_printf(" %s", file->name);
			append_indicator(file);
		}
	}
	else
	{
		ft_printf("%s", file->name);
		append_indicator(file);
		putoffset(width - file->namlen);
	}
}
