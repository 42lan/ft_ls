/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:26:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/21 16:19:04 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>

char				ft_modes(mode_t mode)
{
	O
}

char				*ft_type(mode_t mode)
{
	if (S_ISBLK(mode))
		return ("Block special");
	else if (S_ISCHR(mode))
		return ("Char special");
	else if (S_ISDIR(mode))
		return ("Directory");
	else if (S_ISFIFO(mode))
		return ("FIFO");
	else if (S_ISREG(mode))
		return ("Regular file");
	else if (S_ISLNK(mode))
		return ("Symbolic link");
	else if (S_ISSOCK(mode))
		return ("Socket");
	else
		return ("WHAT???");
}

int					ft_inspect_file(char *path)
{
	struct stat		buf;

	if (stat(path, &buf) != 0)
	{
		printf("ft_inspect_file: %s: No such file or directory\n", path);
		return (0); // Erreur
	}
	printf("Nom: %s\n", path);
	printf("Type: %s\n", ft_type(buf.st_mode));
	printf("Modes: %o\n", ft_modes(buf.st_mode));
	printf("Nombre de liens: %d\n", buf.st_nlink);
	printf("Proprietaire: %u\n", buf.st_uid);
	printf("Group: %u\n", buf.st_gid);
	printf("Taille: %lld\n", buf.st_size);
	printf("Date de derniere modification: buf.st_mtimespec\n");
	return (1); // Ca va bien, merci
}

int					main(int ac, char **av)
{
	int				i;

	i = 0;
	if (ac < 2)
	{
		printf("Usage: ./ft_inspect_file [path ...]\n");
		return (1);
	}
	while (++i < ac)
		ft_inspect_file(av[i]);
	return (0);
}
