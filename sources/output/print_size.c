/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:32:37 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/26 20:19:01 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_size(off_t st_size, size_t width)
{
	if (g_argp[LONG_WITHOUT_OWNER].active && g_argp[LONG_WITHOUT_GROUP].active)
		ft_putchar(' ');
	ft_printf("%*d", width + 2, st_size);
}
