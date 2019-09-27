/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_major_minor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:54:53 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 10:26:58 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			determine_major_minor_wmax(t_wmax *wmax, t_file *file)
{
	size_t		major_w;
	size_t		minor_w;

	major_w = ft_uilen(file->major, 10);
	minor_w = ft_uilen(file->minor, 10);
	if (major_w > wmax->major)
		wmax->major = major_w;
	if (minor_w > wmax->minor)
		wmax->minor = minor_w;
}
