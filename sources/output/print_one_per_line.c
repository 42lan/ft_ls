/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_per_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:46:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/21 18:00:09 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_one_per_line(t_dir *directory)
{
	if (directory->file_head)
		while (directory->file_head != NULL)
		{
			print_filename(directory->file_head, 0);
			ft_putchar('\n');
			directory->file_head = directory->file_head->next;
		}
}
