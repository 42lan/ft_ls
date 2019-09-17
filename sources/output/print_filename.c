/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:18:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/17 13:42:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_filename(t_file *file)
{
	if (g_argp[LONG_FORMAT].active)
	{
		if (S_ISLNK(file->stat->st_mode))
			ft_printf(" %s -> %s", file->name, file->target);
		else
			ft_printf(" %s", file->name);
	}
	else
		ft_printf("%s", file->name);
	//if (g_argp[INDICATOR].active)
	//	append_indicator(file);
	ft_putchar('\n');
}
