/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mtim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:27:57 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 05:13:47 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_mtim(time_t tv_sec)
{
	char	*mtime_str;

	mtime_str = ctime(&tv_sec);
	mtime_str[16] = '\0';
	ft_printf("%s ", mtime_str + 4);
}
