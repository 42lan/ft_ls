/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_major_minor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:54:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/09 12:55:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			determine_major_minor_wmax(t_dir *directory, t_file *file)
{
	ssize_t		major_w;
	ssize_t		minor_w;

	major_w = ft_uilen(file->major, 10);
	minor_w = ft_uilen(file->minor, 10);
	if (major_w > directory->major_wmax)
		directory->major_wmax = major_w;
	if (minor_w > directory->minor_wmax)
		directory->minor_wmax = minor_w;
}
