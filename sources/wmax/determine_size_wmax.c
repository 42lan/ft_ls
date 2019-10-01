/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_size_wmax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 03:59:04 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 13:36:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_size_wmax(t_wmax *wmax, t_file *file)
{
	size_t	size_w;

	size_w = ft_uilen(file->stat.st_size, 10);
	if (size_w > wmax->size)
		wmax->size = size_w;
}
