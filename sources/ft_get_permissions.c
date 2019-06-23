/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_permissions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:46:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/23 13:53:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_get_permissions(mode_t mode, int ugo)
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
