/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_filename_wmax.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 02:26:11 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/21 15:45:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_filename_wmax(t_dir *directory, t_file *file)
{
	if (file->namlen > directory->filename_wmax)
		directory->filename_wmax = file->namlen;
}
