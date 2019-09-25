/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:31:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/25 10:02:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

static void		override(const char option)
{
	if (option == '1')
		g_argp[LONG_FORMAT].active = 0;
	else if (option == 'l')
		g_argp[ONE_PER_LINE].active = 0;
}

void			parse_argp(const char *av)
{
	int			i;
	int			k;
	int			found;

	i = 0;
	while (av[++i] != '\0')
	{
		k = -1;
		found = 0;
		while (g_argp[++k].sign != 0)
			if (g_argp[k].sign == av[i])
			{
				override(av[i]);
				g_argp[k].active = 1;
				found = 1;
			}
		if (found == 0)
			print_usage(av[i]);
	}
}
