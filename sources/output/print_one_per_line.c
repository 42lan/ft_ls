/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_per_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:46:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/23 13:20:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			print_one_per_line(t_dir *directory)
{
	if (directory->file_head)
		while (directory->file_head != NULL)
		{
			print_filename(directory->file_head, 0);
			if (g_argp[INDICATOR].active)
				append_indicator(directory->file_head);
			ft_putchar('\n');
			directory->file_head = directory->file_head->next;
		}
}
