/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:31:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/27 18:46:33 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		parse_argp(int ac, char *av[], t_argp g_argp[])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			j = 1;
			while (av[i][j] != '\0')
			{
				k = 0;
				while (g_argp[k].sign != 0)
				{
					if (g_argp[k].sign == av[i][j])
						g_argp[k].active = 1;
					++k;
				}
				j++;
			}
		}
		i++;
	}
}

