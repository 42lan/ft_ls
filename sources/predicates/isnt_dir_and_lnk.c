/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnt_dir_and_lnk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 13:47:45 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 13:48:11 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		isnt_dir_and_lnk(t_file *file)
{
	if (!((S_ISDIR(file->stat->st_mode) && (S_ISLNK(file->stat->st_mode)))))
		return (1);
	return (0);
}
