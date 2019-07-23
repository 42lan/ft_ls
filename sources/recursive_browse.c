/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_browse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:06:02 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/23 17:32:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive_browse(t_list *sdir_head)
{
	while (sdir_head != NULL)
	{
		write(1, "\n", 1);
		ft_printf("%s :\n", sdir_head->content);
		browse_dir(sdir_head->content);
		sdir_head = sdir_head->next;
	}
}
