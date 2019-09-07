/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:58:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/06 16:47:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_options(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (ft_strequ(av[i], "--"))
			break ;
		else if (is_option(av[i]))
			parse_argp(av[i]);
		else
			break ;
		i++;
	}
}
