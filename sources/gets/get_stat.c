/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:16:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/01 12:36:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_stat(const char *path, t_file *file)
{
	if (path == NULL)
		return (0);
	if (!(file->stat = (struct stat *)ft_memalloc(sizeof(struct stat))))
		return (0);
	return (lstat(path, file->stat));
}
