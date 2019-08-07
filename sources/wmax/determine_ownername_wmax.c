/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_ownername_wmax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:45:31 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/07 12:56:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_ownername_wmax(t_file *file, t_dir *current_dir)
{
	size_t	ownername_w;

	ownername_w = ft_strlen(file->ownername);
	if (ownername_w > current_dir->ownername_wmax)
		current_dir->ownername_wmax = ownername_w;
}
