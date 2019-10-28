/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:20:27 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/27 13:20:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realpath(const char *dirname, char const *basename)
{
	char	*path;

	if (!dirname || !basename)
		return (NULL);
	if (!(path = ft_strnew(ft_strlen(dirname) + 1 + ft_strlen(basename))))
		return (NULL);
	path = ft_strcpy(path, dirname);
	if (!ft_strequ(dirname, "/"))
		path = ft_strcat(path, "/");
	path = ft_strcat(path, basename);
	return (path);
}
