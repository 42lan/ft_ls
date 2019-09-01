/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 12:51:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/01 12:53:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	remove_file(t_file *file)
{
	ft_memdel((void **)&file->name);
	ft_memdel((void **)&file->relpath);
	ft_memdel((void **)&file->stat);
	ft_memdel((void **)&file->ownername);
	ft_memdel((void **)&file->groupname);
	ft_memdel((void **)&file);
	file = NULL;
}

