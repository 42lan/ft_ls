/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:09:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/23 15:21:20 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_list_dir(char *entryname)
{
	t_dir		dir;
	t_entry		entry;

	if ((dir.dp = opendir(entryname)) != NULL)
	{
		while ((dir.de = readdir(dir.dp)) != NULL)
		{
			ft_inspect_entry(&entry, dir.de->d_name);
			//ft_printf("%llu\t%s\n", dir.de->d_ino, dir.de->d_name);
		}
		closedir(dir.dp);
	}
	else
		ft_printf("ft_ls: %s: %s\n", entryname, strerror(errno));
}
