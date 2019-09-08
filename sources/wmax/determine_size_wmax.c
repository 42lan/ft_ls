/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_size_wmax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 03:59:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/08 09:50:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_size_wmax(t_dir *directory, t_file *file)
{

	size_t	size_w;

	size_w = ft_uilen(file->stat->st_size, 10);
	if (size_w > directory->size_wmax)
		directory->size_wmax = size_w;
}
