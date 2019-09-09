/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_extended_attribute.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 10:49:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/09 10:50:30 by amalsago         ###   ########.fr       */
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
