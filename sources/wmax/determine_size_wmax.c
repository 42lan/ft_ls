/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_size_wmax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 03:59:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/24 12:27:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_size_wmax(t_file *file, t_dir *current_dir)
{
	size_t	size_w;

	size_w = ft_uilen(file->stat->st_size, 10);
	if (size_w > current_dir->size_wmax)
		current_dir->size_wmax = size_w;
}
