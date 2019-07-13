/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/12 03:30:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_ls(int ac, char **av)
{
	int				i;
	int				options;
	int				opt_bits;
	struct dirent	*dirent;
	t_dir			current_dir;

	dirent = NULL;
	opt_bits = 0;
	// parse_options() retourne l'index de l'agument qui n'est pas une options
	options = parse_options(ac, av, &opt_bits);
	i = options; // je me la valeur de ce index dans la variable
	if (ac == 0)
	{
		browse_dir(".", dirent, &current_dir);
	}
	// while (i < ac){if ((dp = opendir(av[i])) != NULL){browse_dir(dp, dirent);}closedir(dp);i++;}
	return (1);
}
