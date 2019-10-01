/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_nlink_wmax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 03:59:45 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 13:36:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_nlink_wmax(t_wmax *wmax, t_file *file)
{
	size_t	nlink_w;

	nlink_w = ft_uilen(file->stat.st_nlink, 10);
	if (nlink_w > wmax->nlink)
		wmax->nlink = nlink_w;
}
