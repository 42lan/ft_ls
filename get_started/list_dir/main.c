/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 19:59:00 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/07 10:45:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int					main(int ac, char **av)
{
	int				i;
	DIR				*dp;
	struct dirent	*de;

	i = 0;
	if (ac == 1)
	{
		dp = opendir(".");
		while ((de = readdir(dp)) != NULL)
			printf("%s\n", de->d_name);
		closedir(dp);
	}
	else
	{
		while (++i < ac)
		{
			if ((dp = opendir(av[i])) == NULL)
			{
				printf("ft_ls: %s: No such file or directory\n", av[i]);
				exit(errno);
			}
			while ((de = readdir(dp)) != NULL)
				printf("%s\n", de->d_name);
			closedir(dp);
		}
	}
	return (0);
}
