/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_directory.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:39:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 02:20:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function initialize t_dir structure for each new directory.
*/

void		initialize_directory(t_dir *directory)
{
	directory->length = 0;
	directory->nb_files = 0;
	directory->total_blocks = 0;
	directory->namlen_wmax = 0;
	directory->nlink_wmax = 0;
	directory->size_wmax = 0;
	directory->ownername_wmax = 0;
	directory->groupname_wmax = 0;
}
