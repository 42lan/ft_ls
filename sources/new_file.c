/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:29:55 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/04 15:48:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*new_file(void)
{
	t_file	*new_file;

	if (!(new_file = (t_file *)ft_memalloc(sizeof(t_file))))
		return (NULL);
	new_file->name = NULL;
	new_file->relpath = NULL;
	new_file->namlen = 0;
	new_file->stat = NULL;
	new_file->ownername = NULL;
	new_file->groupname = NULL;
	new_file->next = NULL;
	return (new_file);
}
