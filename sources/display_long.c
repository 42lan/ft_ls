/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 00:52:22 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 05:20:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_long(t_dir *cd, t_entry *entry)
{
	display_mode(entry->stat.st_mode);
	display_nlink(entry->stat.st_nlink, cd->nlink_width);
	display_ownername(entry->passwd->pw_name);
	display_groupname(entry->group->gr_name);
	display_size(entry->stat.st_size, cd->size_width);
	display_mtim(entry->stat.st_mtimespec.tv_sec);
	display_filename(entry->name);
}
