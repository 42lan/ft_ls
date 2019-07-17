/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mtim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:27:57 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 06:03:38 by amalsago         ###   ########.fr       */
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
	int		six_month_ago;
	int		six_month_hence;

	six_month_ago = tv_sec - SIX_MONTH;
	six_month_hence = tv_sec + SIX_MONTH;

	mtime_str = ctime(&tv_sec);
	mtime_str[16] = '\0';
	/*if (tv_sec > six_month_ago)
	{
		mtime_str[24] = '\0';
		ft_printf("%s ", mtime_str + 20);
	}
	else
	*/
		ft_printf("%*s", 1, mtime_str + 4);
}
