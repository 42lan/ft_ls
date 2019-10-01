/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:16:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 13:45:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			get_stat(t_file *file)
{
	char	*path;

	path = (file->relpath == NULL) ? file->name : file->relpath;
	return (lstat(path, &file->stat));
}
