/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_max_width.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:05:30 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/13 05:48:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function is called for each entry while looping through a directory in
** ft_list_dir() to determine the max value of width for size and nlink fields
** from stat struct.
*/

void		determine_max_width(t_dir *directory, t_file *entry)
{
	size_t	size_width;
	size_t	nlink_width;

	size_width = ft_silen(entry->stat.st_size, 10);
	nlink_width = ft_silen(entry->stat.st_nlink, 10);
	if (size_width > directory->size_wmax)
		directory->size_wmax = size_width;
	if (nlink_width > directory->nlink_wmax)
		directory->nlink_wmax = nlink_width;
}
