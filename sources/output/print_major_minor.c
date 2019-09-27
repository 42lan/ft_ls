/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_major_minor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:01:43 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 11:26:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_major_minor(t_wmax *wmax, size_t major, size_t minor)
{
	if (g_argp[LONG_WITHOUT_OWNER].active)
		ft_putchar(' ');
	ft_printf("%*zu, %*zu", wmax->major + 3, major, wmax->minor, minor);
}
