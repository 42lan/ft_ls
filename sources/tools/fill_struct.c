/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:28:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/07 19:09:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_struct(t_file *file, struct dirent *dirent)
{
	struct passwd	*pwstruct;
	struct group	*grstruct;

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
