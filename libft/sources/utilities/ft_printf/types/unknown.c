/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unknown.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:35:14 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/19 15:44:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		specs_handler(t_info *info)
{
	info->hash = 0;
	if (ft_strchr("BbCcDdFfIiOoSsUuXx", info->type) == NULL)
		info->space = 0;
}

void			unknown(const char **format, t_info *info)
{
	t_data		data;

	info->type = **format;
	specs_handler(info);
	data.str = (char *)*format;
	data.length = 1;
	data.negative = 0;
	apply_specs(info, &data);
}
