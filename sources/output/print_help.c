/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 12:51:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 12:58:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_help(void)
{
	int			i;

	i = -1;
	ft_printf("usage: ft_ls [-AFRaglnoprt1] [file ...]\n\n");
	while (g_argp[++i].sign)
		ft_printf("%c - %s\n", g_argp[i].sign, g_argp[i].description);
	exit (EXIT_SUCCESS);
}
