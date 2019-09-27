/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:58:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 12:51:21 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_options(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "--help"))
			print_help();
		else if (ft_strequ(argv[i], "--"))
			break ;
		else if (is_option(argv[i]))
			parse_argp(argv[i]);
		else
			break ;
		i++;
	}
}
