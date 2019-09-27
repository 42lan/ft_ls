/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_wmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:05:30 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 11:11:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function is called for each entry while looping through a directory in
** ft_list_dir() to determine the max value of width for size and nlink fields
** from stat struct.
*/

void	determine_wmax(t_wmax *wmax, t_file *file)
{
	determine_filename_wmax(wmax, file);
	determine_ownername_wmax(wmax, file);
	determine_groupname_wmax(wmax, file);
	determine_nlink_wmax(wmax, file);
	determine_size_wmax(wmax, file);
	determine_major_minor_wmax(wmax, file);
}
