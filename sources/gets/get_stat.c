/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:16:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/19 17:14:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					get_stat(const char *path, t_file *file)
{
	if (path == NULL)
		return (0);
	if (!(file->stat = (struct stat *)ft_memalloc(sizeof(struct stat))))
		return (0);
	if (lstat(path, file->stat) == -1)
	{
		ft_printf("lstat(%s): %s\n", path, strerror(errno));
		return (0);
	}
	return (1);
}
