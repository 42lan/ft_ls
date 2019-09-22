/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_to_skip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 15:54:02 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/22 15:55:22 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

int					need_to_skip(const char *name)
{
	if (g_argp[ALMOST_ALL].active && !(g_argp[SHOW_HIDDEN].active))
	{
		if (is_dotdot(name))
			return (1);
	}
	else if (!(g_argp[SHOW_HIDDEN].active))
	{
		if (is_hidden(name))
			return (1);
	}
	return (0);
}
