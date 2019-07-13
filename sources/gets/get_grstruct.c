/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:52:38 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/13 09:41:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct group		*get_grstruct(gid_t st_gid)
{
	struct group	*group;

	if (!(group = (struct group *)malloc(sizeof(struct group))))
		return (NULL);
	group = getgrgid(st_gid);
	return (group);
}
