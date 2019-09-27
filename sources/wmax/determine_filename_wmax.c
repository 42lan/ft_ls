/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_filename_wmax.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 02:26:11 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 10:24:01 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_filename_wmax(t_wmax *wmax, t_file *file)
{
	if (file->namlen > wmax->filename)
		wmax->filename = file->namlen;
}
