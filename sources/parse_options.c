/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 01:08:05 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 01:07:07 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** parse_options() sets corresponding bit to 1 or sets all bits to 0 if `--`.
*/

void			parse_options(char *str, int *options)
{
	int			i;
	int			n;

	i = 0;
	n = 0;
	if (str[1] == '-')
		*options = 0;
	else
	{
		while (str[++i] != '\0')
		{
			if ((n = ft_strchr_index("lRart", str[i])) == -1)
				return (usage(str[i]));
			*options |= (1 << n);
		}
	}
}
