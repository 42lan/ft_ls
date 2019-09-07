/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_namlen_wmax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 02:26:11 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/07 20:00:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_namlen_wmax(struct dirent *dirent, t_dir *directory)
{
	if (dirent->d_namlen > directory->namlen_wmax)
		directory->namlen_wmax = dirent->d_namlen;
}
