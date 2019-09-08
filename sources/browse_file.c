/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:46:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/08 09:53:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

/*
	{'l', 0, "List in long format"},
	{'a', 0, "List files whose names begin with a dot (.)"},
	{'R', 0, "Recursively list subdirectories encountered"},
	{'r', 0, "Reverse the order of the sort"},
	{'1', 0, "List one file per line"},
	{'t', 0, "Sort by time modified (most recently modified first)"},
	{'-', 0, "End of options"},
	{0, 0, NULL}
*/
void				browse_file(const char *path, t_file *file)
{
	t_dir			*directory;
	struct passwd	*passwd;
	struct group	*group;

	directory = new_directory(path);
	if ((passwd = get_pwstruct(file->stat->st_uid)) == NULL)
		file->ownername = ft_itoa(file->stat->st_uid);
	else
		file->ownername = passwd->pw_name;
	if ((group = get_grstruct(file->stat->st_gid)) == NULL)
		file->groupname = ft_itoa(file->stat->st_gid);
	else
		file->groupname = group->gr_name;
	directory->file_head = file;
	determine_ownername_wmax(directory, file);
	determine_groupname_wmax(directory, file);
	determine_nlink_wmax(directory, file);
	determine_size_wmax(directory, file);
	display(directory);
}
