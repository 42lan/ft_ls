/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 15:12:11 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/09 15:48:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_listdir(const char *path)
{
	DIR				*dp; // Directory pointer
	struct dirent	*de; // Directory entry (file, directory, symlink...)

	if ((dp = opendir(path)) == NULL)
	{
		ft_printf("ft_ls: %s: %s\n", path, strerror(errno));
		return (errno);
	}
	while ((de = readdir(dp)) != NULL)
		ft_printf("%s\n", de->d_name);
	(void)closedir(dp);
	return (1);
}
