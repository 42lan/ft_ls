/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accessibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:40:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 12:20:23 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		check_accessibility(t_file **head)
{
	t_file	*bad_file;
	t_file	**tracer;

	bad_file = NULL;
	tracer = head;
	while ((*tracer))
	{
		if (get_stat((*tracer)) == -1)
		{
			print_ft_ls_error((*tracer)->name, errno);
			bad_file = *tracer;
			remove_file(bad_file);
			*tracer = (*tracer)->next;
		}
		else
			tracer = &(*tracer)->next;
	}
}
