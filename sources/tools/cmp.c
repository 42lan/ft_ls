/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:38:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 13:35:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		mtime_cmp(t_file *a, t_file *b)
{
	return (b->stat.st_mtimespec.tv_sec - a->stat.st_mtimespec.tv_sec);
}

int		name_cmp(t_file *a, t_file *b)
{
	return (ft_strcmp(a->name, b->name));
}
