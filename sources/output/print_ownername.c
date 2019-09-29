/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ownername.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:10:30 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 12:48:17 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_ownername(const char *ownername, size_t width)
{
	if (g_argp[LONG_WITHOUT_OWNER].active == 0)
		ft_printf(" %-*s", width, ownername);
}
