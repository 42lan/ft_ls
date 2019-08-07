/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mtim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:27:57 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/07 12:38:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Supposing that there is 30 days in a month
** 1 minute	= 60 sec
** 1 hour	= 3600 sec
** 1 day	= 86400 sec
** 1 month	= 2592000 sec
** 6 month	= 15552000 sec
*/

#define		SIX_MONTH 15552000

void		display_mtim(time_t tv_sec)
{
	char	*mtime_str;
	char	year[5];
	time_t	current_time;
	time_t	time_diff;

	time(&current_time);
	time_diff = current_time - SIX_MONTH;
	mtime_str = ctime(&tv_sec);
	if (tv_sec < time_diff || tv_sec > current_time)
	{
		ft_memcpy(year, mtime_str + 20, 4);
		mtime_str[10] = '\0';
		ft_printf(" %s  %s", mtime_str + 4, year);
	}
	else
	{
		mtime_str[16] = '\0';
		ft_printf(" %s", mtime_str + 4);
	}
}
