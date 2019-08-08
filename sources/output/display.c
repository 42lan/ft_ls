/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:07:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/08 13:24:57 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			display(t_dir *current_dir)
{
	if (g_argp[LONG_FORMAT].active == 1)
		display_long(current_dir);
	else
		display_default(current_dir);
}
