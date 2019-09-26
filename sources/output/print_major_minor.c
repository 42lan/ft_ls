/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_major_minor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:01:43 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/26 16:20:15 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_major_minor(t_dir *dir, size_t major, size_t minor)
{
	if (g_argp[LONG_WITHOUT_OWNER].active)
		ft_putchar(' ');
	ft_printf("%*zu, %*zu", dir->major_wmax + 3, major, dir->minor_wmax, minor);
}
