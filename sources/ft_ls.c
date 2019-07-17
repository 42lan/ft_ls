/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/17 15:00:30 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_ls(int ac, char **av)
{
	int				i;
	int				options;
	int				opt_bits;
	t_dir			*current_dir;

	opt_bits = 0;
	options = parse_options(ac, av, &opt_bits); // parse_options() retourne l'index de l'agument qui n'est pas une options
	i = options; // je me la valeur de ce index dans la variable
	if (ac == 0)
	{
		current_dir = browse_dir(".");
		display_long(current_dir);
	}
	// while (i < ac){if ((dp = opendir(av[i])) != NULL){browse_dir(dp, dirent);}closedir(dp);i++;}
	return (1);
}
