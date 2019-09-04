/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:31:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/02 16:38:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			parse_argp(const char *av)
{
	int			i;
	int			k;

	i = 0;
	k = -1;
	while (av[++i] != '\0')
	{
		k = -1;
		if (ft_strchr("lRart1", av[i]) == NULL)
			display_usage(av[i]);
		while (g_argp[++k].sign != 0)
			if (g_argp[k].sign == av[i])
				g_argp[k].active = 1;
	}
}
