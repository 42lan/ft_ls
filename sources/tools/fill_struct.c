/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:28:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/28 11:49:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

void				fill_struct(t_file *file)
{
	struct passwd	*pwstruct;
	struct group	*grstruct;

	if (get_stat(file) == -1)
		ft_perror_exit(strerror(errno));
	if (g_argp[LONG_FORMAT].active)
	{
		pwstruct = getpwuid(file->stat.st_uid);
		grstruct = getgrgid(file->stat.st_gid);
		if (pwstruct != NULL && !(g_argp[LONG_NUMERIC_ID].active))
			file->ownername = pwstruct->pw_name;
		else
			file->ownername = ft_itoa(file->stat.st_uid);
		if (grstruct != NULL && !(g_argp[LONG_NUMERIC_ID].active))
			file->groupname = grstruct->gr_name;
		else
			file->groupname = ft_itoa(file->stat.st_gid);
		if (S_ISLNK(file->stat.st_mode))
			get_link(file);
		get_mode(file);
		get_major_minor(file);
	}
}
