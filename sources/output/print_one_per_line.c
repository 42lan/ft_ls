/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_per_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:46:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/26 11:18:50 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_one_per_line(t_dir *directory)
{
	t_file		*file;

	file = directory->file_head;
	if (file)
		while (file != NULL)
		{
			print_filename(file, file->namlen);
			file = file->next;
			ft_putchar('\n');
		}
}
