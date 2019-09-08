/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_namlen_wmax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 02:26:11 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/08 09:48:56 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_namlen_wmax(t_dir *directory, t_file *file)
{
	if (file->namlen > directory->namlen_wmax)
		directory->namlen_wmax = file->namlen;
}
