/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:38:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/15 13:11:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		mtime_cmp(t_file *a, t_file *b)
{
	if (a->stat->st_mtime == b->stat->st_mtime)
		return (a->stat->st_mtimespec.tv_nsec > b->stat->st_mtimespec.tv_nsec);
	else
		return (a->stat->st_mtime - b->stat->st_mtime);
}

int		name_cmp(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name));
}
