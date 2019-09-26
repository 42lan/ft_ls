/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_indicator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:16:11 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/26 13:08:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			append_indicator(t_file *file)
{
	if (g_argp[INDICATOR_SLASH].active && S_ISDIR(file->stat->st_mode))
		ft_putchar('/');
	else if (g_argp[INDICATORS].active)
	{
		if (S_ISDIR(file->stat->st_mode))
			ft_putchar('/');
		else if (S_ISREG(file->stat->st_mode) && (FT_XUGO(file->stat->st_mode)))
			ft_putchar('*');
		else if (S_ISLNK(file->stat->st_mode))
			ft_putchar('@');
		else if (S_ISSOCK(file->stat->st_mode))
			ft_putchar('=');
		else if (S_ISFIFO(file->stat->st_mode))
			ft_putchar('|');
	}
}
