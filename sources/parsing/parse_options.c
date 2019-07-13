/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 01:08:05 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/07 23:59:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This functions sets specific bits for each encountred options.
** It return a number of valid options in order that when returning in ft_ls()
** we start at n-th argument.
*/

int			parse_options(int ac, char **av, int *opt_bits)
{
	int		i;
	int		j;
	int		index;
	int		options; // nubmer of valid options

	i = -1;
	index = 0;
	options = 0;
	while (++i < ac)
	{
		if (ft_strequ(av[i], "--"))
		{
			++options;
			break ;
		}
		if (av[i][0] == '-')
		{
			j = 0;
			++options;
			while (av[i][++j] != '\0')
			{
				if ((index = ft_strchr_index("lRart", av[i][j])) == -1)
				{
					--options;
					display_usage(av[i][j]);
					break ;
				}
				*opt_bits |= (1 << index);
			}
		}
		else
			break ;
	}
	return (options);
}
