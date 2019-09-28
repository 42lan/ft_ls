/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:24:15 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/28 11:43:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void		print_usage(char c)
{
	int		i;

	i = -1;
	ft_print_error("ft_ls: illegal option -- ");
	ft_putchar_fd(c, STDERR_FILENO);
	ft_print_error("\nusage: ft_ls [-");
	while (g_argp[++i].sign)
		ft_putchar_fd(g_argp[i].sign, STDERR_FILENO);
	ft_print_error_and_exit("] [file ...]\n");
}
