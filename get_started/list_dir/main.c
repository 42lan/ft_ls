/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 19:59:00 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/27 19:24:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <string.h>

int					main(int ac, char **av)
{
	DIR				*dirp;
	struct dirent	*dirent;

	if (ac < 2)
	{
		printf("Usage: ./ft_list_dir dirname\n");
		return (1);
	}
	dirp = opendir(av[1]);
	if (dirp == NULL)
	{
		printf("Cannot open the directory\n");
		return (1);
	}
	while ((dirent = readdir(dirp)) != NULL)
		if (strcmp(dirent->d_name, ".") != 0
			&& strcmp(dirent->d_name, "..") != 0)
			printf("%s\n", dirent->d_name);
	closedir(dirp);
	return (0);
}
