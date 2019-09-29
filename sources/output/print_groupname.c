/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_groupname.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:13:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 12:48:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_groupname(const char *groupname, size_t width)
{
	if (g_argp[LONG_WITHOUT_GROUP].active == 0)
	{
		if (g_argp[LONG_WITHOUT_OWNER].active == 0)
			ft_putchar(' ');
		ft_printf(" %-*s", width, groupname);
	}
}
