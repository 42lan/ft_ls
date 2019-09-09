/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_major_minor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:19:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/09 13:38:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_major_minor(t_file *file)
{
	file->major = major(file->stat->st_rdev);
	file->minor = minor(file->stat->st_rdev);
}
