/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/03 15:12:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


int			ft_ls(t_file *head)
{
	t_file	*file;

	file = head;
	while (file)
	{
		if (S_ISDIR(file->stat->st_mode))
			browse_dir(file->name);
		else if (S_ISREG(file->stat->st_mode))
			browse_file(file->name, file);
		file = file->next;
	}
	return (1);
}
