/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_ownername_wmax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:45:31 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 10:24:53 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		determine_ownername_wmax(t_wmax *wmax, t_file *file)
{
	size_t	ownername_w;

	ownername_w = ft_strlen(file->ownername);
	if (ownername_w > wmax->ownername)
		wmax->ownername = ownername_w;
}
