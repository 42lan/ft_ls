/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:38:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/23 13:12:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			mtime_cmp(t_file *a, t_file *b)
{
	int		diff;

	diff = a->stat->st_mtime - b->stat->st_mtime;
	if (a->stat->st_mtime == b->stat->st_mtime)
		diff = (a->stat->st_mtimespec.tv_nsec == b->stat->st_mtimespec.tv_nsec)
			? 1 : a->stat->st_mtimespec.tv_nsec > b->stat->st_mtimespec.tv_nsec;
	return (diff);
}

int		name_cmp(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name));
}
