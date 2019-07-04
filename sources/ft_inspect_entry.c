/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inspect_entry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:26:51 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 02:37:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_inspect_entry(t_entry *entry, char *entryname)
{
	char			*date;
	char			mode_str[10];

	if (stat(entryname, &entry->stat) != 0)
		return (0);
	entry->passwd = getpwuid(entry->stat.st_uid);
	entry->group = getgrgid(entry->stat.st_gid);
	entry->timestamp = entry->stat.st_mtimespec.tv_sec;
	date = ctime(&entry->timestamp);
	ft_printf("%c", ft_type(entry->stat.st_mode));
	modecat(mode_str, entry->stat.st_mode);
	ft_printf("%s", mode_str);
	ft_printf("%3d", entry->stat.st_nlink);
	ft_printf(" %s ", entry->passwd->pw_name);
	ft_printf("%s", entry->group->gr_name);
	ft_printf("%10d", entry->stat.st_size);
	date[16] = '\0';
	ft_printf(" %s", date + 4);
	ft_printf(" %s\n", entry->name);
	return (1);
}
