/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:26:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/22 19:15:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>
#include <string.h>

char				*get_permissions(mode_t mode, int ugo)
{
	if (mode & S_IRUSR >> ugo && mode & S_IWUSR >> ugo && mode & S_IXUSR >> ugo)
		return ("rwx");
	else if ((mode & S_IRUSR >> ugo) && (mode & S_IWUSR >> ugo))
		return ("rw-");
	else if ((mode & S_IRUSR >> ugo) && (mode & S_IXUSR >> ugo))
		return ("r-x");
	else if (mode & S_IRUSR >> ugo)
		return ("r--");
	else if ((mode & S_IWUSR >> ugo) && (mode & S_IXUSR >> ugo))
		return ("-wx");
	else if (mode & S_IWUSR >> ugo)
		return ("-w-");
	else if (mode & S_IXUSR >> ugo)
		return ("--x");
	else
		return ("---");
}

void				ft_modes(char *modes_str, mode_t mode)
{
	strcat(modes_str, get_permissions(mode, 0));
	strcat(modes_str, get_permissions(mode, 3));
	strcat(modes_str, get_permissions(mode, 6));
	modes_str[9] = '\0';
}

char				ft_type(mode_t mode)
{
	if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISFIFO(mode))
		return ('p');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISSOCK(mode))
		return ('s');
	else
		return ('-');
}

int					ft_inspect_file(char *path)
{
	struct stat		buf;
	struct passwd	*passwd;
	struct group	*group;
	time_t			timesec;
	char			modes_str[10];

	if (stat(path, &buf) != 0)
	{
		printf("ft_inspect_file: %s: No such file or directory\n", path);
		return (0); // Erreur
	}
	passwd = getpwuid(buf.st_uid);
	group = getgrgid(buf.st_gid);
	timesec = buf.st_mtimespec.tv_sec;
	printf("Name:\t%s\n", path);
	printf("Type:\t%c\n", ft_type(buf.st_mode));
	ft_modes(modes_str, buf.st_mode);
	printf("Mode:\t%s\n", modes_str);
	printf("Links:\t%d\n", buf.st_nlink);
	printf("Owner:\t%s\n", passwd->pw_name);
	printf("Group:\t%s\n", group->gr_name);
	printf("Size:\t%lld\n", buf.st_size);
	printf("Modify:\t%s", ctime(&timesec));
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
