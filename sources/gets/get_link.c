/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:36:31 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/08 10:51:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_link(t_file *file)
{
	char	*pathname;

	pathname = (file->relpath != NULL) ? file->relpath : file->name;
	readlink(pathname, file->target, sizeof(file->target) - 1);
	file->targetlen = ft_strlen(file->target);
	file->target[file->targetlen] = '\0';
}
