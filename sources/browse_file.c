/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:46:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/25 13:29:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	browse_file(const char *path)
{
	t_file			*file;

	file = new_file();
	file->stat = get_stat(path);
	struct passwd	*passwd;
	struct group	*group;

	if ((passwd = get_pwstruct(file->stat->st_uid)) == NULL) //// Need to quit properly
		return ; //////////////////////////////////////////////// Need to quit properly
	if ((group = get_grstruct(file->stat->st_gid)) == NULL) ///// Need to quit properly
		return ; //////////////////////////////////////////////// Need to quit properly
	file->name = ft_strdup(path);
	file->namlen = ft_strlen(path);
	file->ownername = passwd->pw_name;
	file->groupname = group->gr_name;
	display_filename(file->name, 0);
}
