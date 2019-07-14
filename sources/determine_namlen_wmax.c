/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_namlen_wmax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 02:26:11 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 04:00:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_namlen_wmax(struct dirent *dirent, t_dir *current_dir)
{
	if (dirent->d_namlen > current_dir->namlen_wmax)
		current_dir->namlen_wmax = dirent->d_namlen;
}
