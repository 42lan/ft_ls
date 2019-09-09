/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:28:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/09 13:19:08 by amalsago         ###   ########.fr       */
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
	file->ownername = (pwstruct != NULL) ? pwstruct->pw_name : ft_itoa(file->stat->st_uid);
	file->groupname = (grstruct != NULL) ? grstruct->gr_name : ft_itoa(file->stat->st_uid);
	if (S_ISLNK(file->stat->st_mode))
		get_link(file);
	get_mode(file);
	get_major_minor(file);
}
