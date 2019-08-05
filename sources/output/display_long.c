/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:19:46 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/05 11:35:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_long(t_dir *current_dir)
{
	if (current_dir->file_head->next != NULL)
		display_total(current_dir->total_blocks);
	while (current_dir->file_head != NULL)
	{
		display_mode(current_dir->file_head->stat->st_mode);
		display_nlink(current_dir->file_head->stat->st_nlink, current_dir->nlink_wmax);
		display_ownername(current_dir->file_head->ownername, current_dir->ownername_wmax);
		display_groupname(current_dir->file_head->groupname, current_dir->groupname_wmax);
		display_size(current_dir->file_head->stat->st_size, current_dir->size_wmax);
		display_mtim(current_dir->file_head->stat->st_mtimespec.tv_sec);
		display_filename(current_dir->file_head->name, 1);
		ft_putchar('\n');
		current_dir->file_head = current_dir->file_head->next;
	}
}
