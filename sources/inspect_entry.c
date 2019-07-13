/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:26:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/13 05:51:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					inspect_entry(t_file *file, char *entryname)
{
	/*
	char			*date;
	char			mode_str[10];

	if (stat(entryname, &file->stat) != 0)
		return (0);
	file->passwd = getpwuid(file->stat.st_uid);
	file->group = getgrgid(file->stat.st_gid);
	//file->stat->timestamp = file->stat.st_mtimespec.tv_sec;
	date = ctime(&file->stat.st_mtimespec.tv_sec);
	modecat(mode_str, file->stat.st_mode);
	*/
	(void)file; (void)entryname;
	return (1);
}
