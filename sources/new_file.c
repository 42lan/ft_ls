/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 15:29:55 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/16 15:30:50 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*new_file(void)
{
	t_file	*new_file;

	if (!(new_file = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new_file->next = NULL;
	return (new_file);
}
