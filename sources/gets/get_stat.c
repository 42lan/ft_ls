/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:16:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/08 11:50:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					get_stat(const char *path, t_file *file)
{
	if (path == NULL)
		return (0);
	if (!(file->stat = (struct stat *)ft_memalloc(sizeof(struct stat))))
		return (0);
	if (stat(path, file->stat) == -1)
	{
		ft_printf("get_stat(): %s\n", strerror(errno));
		return (0);
	}
	return (1);
}
