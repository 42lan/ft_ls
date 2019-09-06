/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:28:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/06 16:21:03 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_file_struct(t_file *file, struct dirent *dirent)
{
	struct passwd	*pwstruct;
	struct group	*grstruct;

	file->name = dirent->d_name;
	file->namlen = dirent->d_namlen;
	if ((pwstruct = get_pwstruct(file->stat->st_uid)) != NULL)
		file->ownername = pwstruct->pw_name;
	else
		file->ownername = ft_itoa(file->stat->st_uid);
	if ((grstruct = get_grstruct(file->stat->st_gid)) != NULL)
		file->groupname = grstruct->gr_name;
	else
		file->groupname = ft_itoa(file->stat->st_uid);
}
