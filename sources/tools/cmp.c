/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 11:38:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/01 11:38:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		mtime_cmp(t_file *file_a, t_file *file_b)
{
	return (file_a->stat->st_mtime - file_b->stat->st_mtime);
}

int		name_cmp(t_file *file_a, t_file *file_b)
{
	return (ft_strcmp(file_a->name, file_b->name));
}
