/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_accessibility.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 13:40:18 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/06 16:51:39 by amalsago         ###   ########.fr       */
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
			ft_strerror("ft_ls: ");
			ft_strerror((*tracer)->name);
			ft_strerror(" : No such file or directory\n");
			bad_file = *tracer;
			remove_file(bad_file);
			*tracer = (*tracer)->next;
		}
		else
			tracer = &(*tracer)->next;
	}
}
