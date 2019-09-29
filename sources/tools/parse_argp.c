/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 18:31:16 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 08:36:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp	g_argp[];

void			override_options(const char option)
{
	if (option == g_argp[INDICATORS].sign)
		g_argp[INDICATOR_SLASH].active = 0;
	else if (option == g_argp[LONG_WITHOUT_OWNER].sign)
	{
		g_argp[LONG_FORMAT].active = 1;
		g_argp[ONE_PER_LINE].active = 0;
	}
	else if (option == g_argp[LONG_FORMAT].sign)
		g_argp[ONE_PER_LINE].active = 0;
	else if (option == g_argp[LONG_NUMERIC_ID].sign)
		g_argp[LONG_FORMAT].active = 1;
	else if (option == g_argp[LONG_WITHOUT_GROUP].sign)
		g_argp[LONG_FORMAT].active = 1;
	else if (option == g_argp[INDICATOR_SLASH].sign)
		g_argp[INDICATORS].active = 0;
	else if (option == g_argp[ONE_PER_LINE].sign)
		g_argp[LONG_FORMAT].active = 0;
}

void			parse_argp(const char *argv)
{
	int			i;
	int			k;
	int			found;

	i = 0;
	while (argv[++i] != '\0')
	{
		k = -1;
		found = 0;
		while (g_argp[++k].sign != 0)
			if (g_argp[k].sign == argv[i])
			{
				override_options(argv[i]);
				g_argp[k].active = 1;
				found = 1;
			}
		if (found == 0)
			print_usage(argv[i]);
	}
}
