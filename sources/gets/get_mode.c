/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:45:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 13:42:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_mode(t_file *file)
{
	file->mode[0] = get_type(file->stat.st_mode);
	ft_strcat(file->mode, get_permissions(file->stat.st_mode, 0));
	ft_strcat(file->mode, get_permissions(file->stat.st_mode, 3));
	ft_strcat(file->mode, get_permissions(file->stat.st_mode, 6));
	set_special_permissions(file->stat.st_mode, file->mode);
	set_extended_attribute(file);
}
