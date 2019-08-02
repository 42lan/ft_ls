/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:31:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/02 20:44:35 by aslan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			parse_argp(char *av)
{
	int			i;
	int			k;

	i = 0; // Start with second (index 1) character
	k = -1;
	while (av[++i] != '\0')
	{
		k = -1;
		while (g_argp[++k].sign != 0)
			if (g_argp[k].sign == av[i])
				g_argp[k].active = 1;
	}
}
