/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:28:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/09 16:08:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

void				fill_struct(t_file *file)
{
	struct passwd	*pwstruct;
	struct group	*grstruct;

	pwstruct = get_pwstruct(file->stat->st_uid);
	grstruct = get_grstruct(file->stat->st_gid);
	if (pwstruct != NULL)
		file->ownername = pwstruct->pw_name;
	else
		file->ownername = ft_itoa(file->stat->st_uid);
	if (grstruct != NULL)
		file->groupname = grstruct->gr_name;
	else
		file->groupname = ft_itoa(file->stat->st_uid);
	if (S_ISLNK(file->stat->st_mode))
		get_link(file);
	get_mode(file);
	get_major_minor(file);
}
