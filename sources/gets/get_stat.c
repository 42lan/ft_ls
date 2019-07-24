/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:16:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/24 18:57:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct stat			*get_stat(const char *path)
{
	struct stat		*file_stat;

	if (path == NULL)
		return (NULL);
	if (!(file_stat = (struct stat *)ft_memalloc(sizeof(struct stat))))
		return (NULL);
	stat(path, file_stat);
	return (file_stat);
}
