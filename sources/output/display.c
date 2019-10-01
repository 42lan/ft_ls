/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:07:44 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 13:28:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			display(t_dir *directory)
{
	if (g_argp[LONG_FORMAT].active)
		print_long(directory);
	else if (g_argp[ONE_PER_LINE].active)
		print_one_per_line(directory);
	else
		print_default(directory);
}
