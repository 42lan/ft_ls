/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accessibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:40:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/03 10:11:02 by amalsago         ###   ########.fr       */
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
		if (get_stat((*tracer)->name, (*tracer)) == -1)
		{
			ft_printf("ft_ls: %s : No such file or directory\n", (*tracer)->name);
			bad_file = *tracer;
			remove_file(bad_file);
			*tracer = (*tracer)->next;
		}
		else
			tracer = &(*tracer)->next;
	}
}
