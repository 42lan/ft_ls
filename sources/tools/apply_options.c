/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:13:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 18:15:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

void				apply_options(t_dir *directory)
{
	if (directory->subdir_head != NULL)
		ft_mergesort(&directory->subdir_head, &name_cmp);
	if (directory->file_head != NULL)
		ft_mergesort(&directory->file_head, &name_cmp);
	if (g_argp[MTIME_SORT].active)
		ft_mergesort(&directory->file_head, &mtime_cmp);
	if (g_argp[REVERSE_ORDER].active)
	{
		reverse_files(&directory->subdir_head);
		reverse_files(&directory->file_head);
	}
}
