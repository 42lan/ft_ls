/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:28:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/24 12:27:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_file_struct(t_file *file, struct dirent *dirent)
{
	struct passwd	*passwd;
	struct group	*group;
	char			*relative_name;

	relative_name = form_path(file->dirname, dirent->d_name);
	//ft_printf("<< %s\n", relative_name);
	file->stat = get_stat(relative_name);
	if ((passwd = get_pwstruct(file->stat->st_uid)) == NULL)
		return ;
	if ((group = get_grstruct(file->stat->st_gid)) == NULL)
		return ;
	file->name = dirent->d_name;
	file->namlen = dirent->d_namlen;
	file->ownername = passwd->pw_name;
	file->groupname = group->gr_name;
}
