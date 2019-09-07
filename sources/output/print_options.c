/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 11:47:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/07 13:32:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_options(t_argp g_argp[])
{
	int		i;

	i = -1;
	while (g_argp[++i].sign)
		ft_printf("%c ", g_argp[i].sign);
	ft_putchar('\n');
	i = -1;
	while (g_argp[++i].sign)
		ft_printf("%d ", g_argp[i].active);
	ft_putchar('\n');
}
