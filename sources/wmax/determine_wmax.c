/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_wmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:05:30 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 04:03:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function is called for each entry while looping through a directory in
** ft_list_dir() to determine the max value of width for size and nlink fields
** from stat struct.
*/

void	determine_wmax(struct dirent *dirent, t_file *file, t_dir *current_dir)
{
	determine_namlen_wmax(dirent, current_dir);
	determine_nlink_wmax(file, current_dir);
	determine_size_wmax(file, current_dir);
}
