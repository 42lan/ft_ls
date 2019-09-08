/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:45:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/08 13:48:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_extended_attribute(t_file *file)
{
	if (listxattr(file->relpath, NULL, 0, XATTR_NOFOLLOW) > 0)
		file->mode[10] = '@';
	else if (acl_get_file(file->relpath, ACL_TYPE_EXTENDED) != NULL)
		file->mode[10] = '+';
	else
		file->mode[10] = ' ';
}

void	get_mode(t_file *file)
{
	file->mode = ft_memalloc(12);
	file->mode[0] = get_type(file->stat->st_mode);
	ft_strcat(file->mode, get_permissions(file->stat->st_mode, 0));
	ft_strcat(file->mode, get_permissions(file->stat->st_mode, 3));
	ft_strcat(file->mode, get_permissions(file->stat->st_mode, 6));
	set_special_permissions(file->stat->st_mode, &file->mode);
	set_extended_attribute(file);
}
