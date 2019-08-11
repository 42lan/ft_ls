/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 14:58:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/11 14:58:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_options(char ***av)
{
	while (**av)
	{
		if (ft_strequ(**av, "--"))
			break;
		else if (is_option(**av))
			parse_argp(**av);
		else
			break;
		(*av)++;
	}
}

