/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_groupname_wmax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:53:31 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 10:25:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_groupname_wmax(t_wmax *wmax, t_file *file)
{
	size_t	groupname_w;

	groupname_w = ft_strlen(file->groupname);
	if (groupname_w > wmax->groupname)
		wmax->groupname = groupname_w;
}
