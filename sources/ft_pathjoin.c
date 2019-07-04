/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 15:59:17 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/30 16:00:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_pathjoin(const char *parent, char const *child)
{
	char	*path;

	if (!parent || !child)
		return (NULL);
	if (!(path = ft_strnew(ft_strlen(parent) + 1 + ft_strlen(child))))
		return (NULL);
	path = ft_strcpy(path, parent);
	path = ft_strcat(path, "/");
	path = ft_strcat(path, child);
	return (path);
}
