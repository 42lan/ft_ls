/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 07:25:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_ls(int ac, char **av)
{
	int				i;
	DIR				*dp;
	t_dir			cd;
	t_entry			entry;
	int				options;
	t_list			sdl;	// sub directory list
	struct dirent	*de;


	i = -1;
	dp = NULL;
	options = 0;
	if (ac == 0)
	{
		cd.parent_name = NULL;
		dp = opendir(".");
		ft_list_dir(dp, &cd, ".", &sdl);
		closedir(dp);
	}
	else
	{
		if (av[0][0] == '-' && av[0][1] != '\0')
		{
			parse_options(av[0], &options);
			++i;
		}
		while (++i < ac)
		{
			if ((dp = opendir(av[i])) != NULL)
			{
				ft_list_dir(dp, &cd, av[i], &sdl);
				determine_max_width(&cd, &entry);
				closedir(dp);
				dp = opendir(av[i]);
				while ((de = readdir(dp)) != NULL)
				{
					entry.name = de->d_name;
					stat(ft_pathjoin(av[i], de->d_name), &entry.stat);
					stat(entry.name, &entry.stat);
					get_pwstruct(entry.stat.st_uid, &entry.passwd);
					get_grstruct(entry.stat.st_gid, &entry.group);
					display_long(&cd, &entry);
				}
				closedir(dp);
			}
			else
			{
				stat(entry.name, &entry.stat);
				entry.name = av[i];
				if (ft_inspect_entry(&entry, av[i]) != 1)
					ft_printf("ft_ls: %s: %s\n", av[i], strerror(errno));
			}
		}
	}
	return (1);
}
