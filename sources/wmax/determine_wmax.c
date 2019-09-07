/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_wmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:05:30 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/07 20:01:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function is called for each entry while looping through a directory in
** ft_list_dir() to determine the max value of width for size and nlink fields
** from stat struct.
*/

void	determine_wmax(struct dirent *dirent, t_file *file, t_dir *directory)
{
	determine_namlen_wmax(dirent, directory);
	determine_ownername_wmax(file, directory);
	determine_groupname_wmax(file, directory);
	determine_nlink_wmax(file, directory);
	determine_size_wmax(file, directory);
}
