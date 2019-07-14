/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:19:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 07:15:06 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_long(t_dir *current_dir, t_file *list)
{
	list = list->next;
	while (list != NULL)
	{
		display_mode(list->stat.st_mode);
		display_nlink(list->stat.st_nlink, current_dir->nlink_wmax);
		display_ownername(list->ownername, 0);
		display_groupname(list->groupname, 0);
		display_size(list->stat.st_size, current_dir->size_wmax);
		display_mtim(list->stat.st_mtimespec.tv_sec);
		display_filename(list->name, 1);
		ft_putstr("\n");
		list = list->next;
	}
}
