/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_nlink_wmax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 03:59:45 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/07 20:01:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_nlink_wmax(t_file *file, t_dir *directory)
{
	size_t	nlink_w;

	nlink_w = ft_uilen(file->stat->st_nlink, 10);
	if (nlink_w > directory->nlink_wmax)
		directory->nlink_wmax = nlink_w;
}
