/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:26:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/23 19:30:27 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_inspect_entry(t_entry *entry, char *path)
{
	char			modes_str[10];
	int				nlink_width;
	int				size_width;

	nlink_width = 1;
	size_width = 1;
	if (stat(path, &entry->stat) != 0)
	{
		ft_printf("ft_inspect_entry: %s: %s\n", path, strerror(errno));
		return (0); // Erreur
	}
	entry->passwd = getpwuid(entry->stat.st_uid);
	entry->group = getgrgid(entry->stat.st_gid);
	entry->timestamp = entry->stat.st_mtimespec.tv_sec;
	ft_modes(modes_str, entry->stat.st_mode);
	ft_printf("%10s", modes_str);
	if (entry->stat.st_nlink > nlink_width)
		nlink_width = ft_silen(entry->stat.st_nlink, 10);
	ft_printf("%3d", entry->stat.st_nlink);
	ft_printf(" %s\t", entry->passwd->pw_name);
	ft_printf("%s", entry->group->gr_name);
	if (entry->stat.st_size > size_width)
		size_width = ft_silen(entry->stat.st_size, 10);
	ft_printf("%*d\t", size_width + 2, entry->stat.st_size);
	ft_printf(" %s\r", ctime(&entry->timestamp));
	//ft_printf("%s\r", );
	return (1); // Ca va bien, merci
}
