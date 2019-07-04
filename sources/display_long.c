/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 00:52:22 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 04:54:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_long(t_entry *entry)
{
	display_mode(entry->stat.st_mode);
										// need to pass dinamyc width
	display_nlink(entry->stat.st_nlink, 3);
	display_ownername(entry->passwd->pw_name);
	display_groupname(entry->group->gr_name);
									  // need to pass dinamyc width
	display_size(entry->stat.st_size, 10);
	display_mtim(entry->stat.st_mtimespec.tv_sec);
	display_filename(entry->name);
}
