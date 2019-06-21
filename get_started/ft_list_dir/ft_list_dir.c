/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 19:59:00 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/21 12:32:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>

void				ft_list_dir(char *filename)
{
	DIR				*dp;
	struct dirent	*de;

	if ((dp = opendir(filename)) != NULL)
	{
		while ((de = readdir(dp)) != NULL)
			printf("%p\t%llu\t%s\n", de, de->d_ino, de->d_name);
		printf("%p\n", de);
		closedir(dp);
	}
	else
		printf("ft_list_dir: %s: No such file or directory\n", filename);
}

int					main(int ac, char **av)
{
	int				i;

	i = 0;
	if (ac == 1)
		ft_list_dir(".");
	else
		while (++i < ac)
			ft_list_dir(av[i]);
	return (0);
}
