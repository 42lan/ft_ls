/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_indicator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:16:11 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/17 13:44:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			append_indicator(t_file *file)
{
	if (S_ISDIR(file->stat->st_mode))
		ft_strcat(file->name, "/");
	else if (S_ISREG(file->stat->st_mode) && file->mode[3] == 'x')
		ft_strcat(file->name, "*");
	else if (S_ISLNK(file->stat->st_mode))
		ft_strcat(file->name, "@");
	else if (S_ISSOCK(file->stat->st_mode))
		ft_strcat(file->name, "=");
	else if (S_ISFIFO(file->stat->st_mode))
		ft_strcat(file->name, "|");
	/*if (S_ISDIR(file->stat->st_mode))
		ft_putchar('/');
	else if (S_ISREG(file->stat->st_mode) && file->mode[3] == 'x')
		ft_putchar('*');
	else if (S_ISLNK(file->stat->st_mode))
		ft_putchar('@');
	else if (S_ISSOCK(file->stat->st_mode))
		ft_putchar('=');
	else if (S_ISFIFO(file->stat->st_mode))
		ft_putchar('|');
	*/
	/*
	else if (S_ISSSSSSSSSSSSSSSSSSSSSSSSSS(file->stat->st_mode))
		ft_putchar('%');
	*/
}
