/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 00:52:22 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/13 05:49:50 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_long(t_dir *cd, t_file *entry)
{
	display_mode(entry->stat.st_mode);
	display_nlink(entry->stat.st_nlink, cd->nlink_wmax);
	display_ownername(entry->ownername, cd->ownername_wmax);
	display_groupname(entry->groupname, cd->groupname_wmax);
	display_size(entry->stat.st_size, cd->size_wmax);
	display_mtim(entry->stat.st_mtimespec.tv_sec);
	display_filename(entry->name);
}
