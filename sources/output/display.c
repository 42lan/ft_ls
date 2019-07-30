/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:07:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/30 09:08:04 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			display(t_dir *current_dir)
{
	if (g_argp[0].active == 1) // If -l is specified
		display_long(current_dir);
	else
		display_default(current_dir);
}
