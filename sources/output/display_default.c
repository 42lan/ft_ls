/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 07:17:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_default(t_dir *current_dir, t_file *list)
{
	printf("%s %zu\n", list->name, current_dir->namlen_wmax);
	list = list->next;
	while (list != NULL)
	{
		//display_filename(list->name, -current_dir->namlen_wmax);
		list = list->next;
	}
}
