/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 03:21:49 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/17 17:40:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_default(t_dir *current_dir)
{
	while (current_dir->head != NULL)
	{
		display_filename(current_dir->head->name, 0);
		ft_putendl("");
		current_dir->head = current_dir->head->next;
	}
}
