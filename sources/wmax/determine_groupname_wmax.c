/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_groupname_wmax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:53:31 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/07 12:57:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_groupname_wmax(t_file *file, t_dir *current_dir)
{
	size_t	groupname_w;

	groupname_w = ft_strlen(file->groupname);
	if (groupname_w > current_dir->groupname_wmax)
		current_dir->groupname_wmax = groupname_w;
}
