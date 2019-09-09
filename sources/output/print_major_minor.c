/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_major_minor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:01:43 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/09 12:42:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_major_minor(t_dir *dir, size_t major, ssize_t minor)
{
	ft_printf("%*zu, %*zu", dir->major_wmax + 3, major, dir->minor_wmax, minor);
}
