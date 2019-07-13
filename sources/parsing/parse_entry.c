/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:38:41 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/26 20:46:37 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** This function parse the entry to determine filename, current directory name
** and parent name of current directory.
*/

void		parse_entry(char *entryname, t_dir *cd_struct)
{
	if (ft_strequ(entryname, ".")) // If current directory is "."
	{
		cd_struct->name = entryname;
		cd_struct->length = ft_strlen(entryname);
		cd_struct->parent_name = NULL;
	}
	else
	{
		if (ft_strequ(entryname, "/"))
		{
			cd_struct->name = entryname;
			cd_struct->length = ft_strlen(entryname);
			cd_struct->parent_name = NULL;
		}
		else
		{
			cd_struct->name = ft_strrchr(entryname, '/') + 1;
			//cd_struct->parent_name = ft_strchr(entryname, '/');
			cd_struct->length = ft_strlen(ft_strrchr(entryname, '/') + 1);
		}
	}
}
