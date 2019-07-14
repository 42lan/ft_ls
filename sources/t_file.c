/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:29:07 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 05:31:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file				*new_file(void)
{
	t_file			*new_file;

	if (!(new_file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new_file->next = NULL;
	return (new_file);
}

t_file				*add_file(t_file *list, t_file *new_file)
{
	t_file			*tmp;

	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_file;
	new_file->next = NULL;
	return (tmp);
}
