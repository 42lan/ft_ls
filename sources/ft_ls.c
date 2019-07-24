/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/24 19:40:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_ls(int ac, char **av)
{
	int				i;
	int				options;
	int				opt_bits;

	i = -1;
	opt_bits = 0;
	options = parse_options(ac, av, &opt_bits); // parse_options() retourne l'index de l'agument qui n'est pas une options
	if (ac == 0)
		browse_dir(".");
	else
		while (++i < ac)
			browse_dir(av[i]);
	return (1);
}
