/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 18:18:08 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 18:19:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	append_file(t_dir **directory, t_file *file)
{
	if ((*directory)->file_head == NULL)
		(*directory)->file_head = file;
	else
	{
		file->next = (*directory)->file_head;
		(*directory)->file_head = file;
	}
}
