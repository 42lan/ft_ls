/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:26:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/27 20:10:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>

int					main(int ac, char **av)
{
	struct stat		buf;

	if (ac < 2)
	{
		printf("Usage: ./ft_inspect_file filename\n");
		return (1);
	}
	stat(av[1], &buf);
	printf("Nom: %s\n", av[1]);
	printf("Type: %o\n", buf.st_mode);
	printf("Modes: %o\n", buf.st_mode);
	printf("Nombre de liens: %d\n", buf.st_nlink);
	printf("Proprietaire: %u\n", buf.st_uid);
	printf("Group: %u\n", buf.st_gid);
	printf("Taille: %lld\n", buf.st_size);
	//printf("Date de derniere modification: %lld\n", buf.st_mtimespec);
	return (0);
}
