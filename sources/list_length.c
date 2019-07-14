/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 05:18:48 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 05:19:07 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t		list_length(t_file *list)
{
	int		length;

	length = 0;
	if (list->next == NULL)
		return (0);
	while (list != NULL)
	{
		++length;
		list = list->next;
	}
	return (length);
}
