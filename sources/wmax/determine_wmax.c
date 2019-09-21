/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_wmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:05:30 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/21 11:14:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function is called for each entry while looping through a directory in
** ft_list_dir() to determine the max value of width for size and nlink fields
** from stat struct.
*/

void	determine_wmax(t_dir *directory, t_file *file)
{
	determine_filename_wmax(directory, file);
	determine_ownername_wmax(directory, file);
	determine_groupname_wmax(directory, file);
	determine_nlink_wmax(directory, file);
	determine_size_wmax(directory, file);
	determine_major_minor_wmax(directory, file);
}
