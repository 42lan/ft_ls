/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 10:27:47 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/20 16:26:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		specs_handler(t_info *info)
{
	info->hash = 0;
	info->plus = 0;
	info->space = 0;
	info->precision = 0;
}

void			percent(const char **format, t_info *info)
{
	t_data		data;

	info->type = **format;
	data.str = "%";
	data.length = 1;
	data.negative = 0;
	specs_handler(info);
	apply_specs(info, &data);
}
