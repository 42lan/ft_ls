/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:28:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/24 19:05:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_file_struct(t_file *file, struct dirent *dirent)
{
	struct passwd	*passwd;
	struct group	*group;

	if ((passwd = get_pwstruct(file->stat->st_uid)) == NULL) //// Need to quit properly
		return ; //////////////////////////////////////////////// Need to quit properly
	if ((group = get_grstruct(file->stat->st_gid)) == NULL) ///// Need to quit properly
		return ; //////////////////////////////////////////////// Need to quit properly
	file->name = dirent->d_name;
	file->namlen = dirent->d_namlen;
	file->ownername = passwd->pw_name;
	file->groupname = group->gr_name;
}
