/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_nlink_wmax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 03:59:45 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/24 12:27:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_nlink_wmax(t_file *file, t_dir *current_dir)
{
	size_t	nlink_w;

	nlink_w = ft_uilen(file->stat->st_nlink, 10);
	if (nlink_w > current_dir->nlink_wmax)
		current_dir->nlink_wmax = nlink_w;
}
