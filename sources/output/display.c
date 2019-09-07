/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:07:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/07 14:18:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			display(t_dir *current_dir)
{
	if (g_argp[LONG_FORMAT].active == 1)
		print_long(current_dir);
	else
		print_default(current_dir);
}
