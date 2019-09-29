/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mtime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:27:57 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 09:50:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#define SIX_MONTH 15552000

extern t_argp	g_argp[];

/*
** Supposing that there is 30 days in a month
** 1 minute	= 60 sec
** 1 hour	= 3600 sec
** 1 day	= 86400 sec
** 1 month	= 2592000 sec
** 6 month	= 15552000 sec
*/

void		print_mtime(time_t tv_sec)
{
	char	year[6];
	char	*mtime_str;
	time_t	current_time;

	ft_bzero(year, 6);
	time(&current_time);
	mtime_str = ctime(&tv_sec);
	if (tv_sec < (current_time - SIX_MONTH) || tv_sec > current_time)
	{
		if (tv_sec > current_time)
			ft_memccpy(year, mtime_str + 24, '\n', ft_strlen(mtime_str + 24) - 1);
		else
			ft_memccpy(year, mtime_str + 20, '\n', ft_strlen(mtime_str + 20) - 1);
		mtime_str[(g_argp[COMPLETE_TIME].active) ? 19 : 10] = '\0';
	}
	mtime_str[(g_argp[COMPLETE_TIME].active) ? 24 : 16] = '\0';
	ft_printf(" %s", mtime_str + 4);
	if (year[0] != '\0')
		ft_printf("%*s", (g_argp[COMPLETE_TIME].active) ? 1 : 2, year);
}
