/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 19:37:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/20 12:15:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			specs_handler(t_info *info)
{
	info->hash = 0;
	info->plus = 0;
	if (info->point == 0)
		info->precision = 7;
}

void				type_f(const char **format, t_info *info)
{
	long double		number;
	t_data			data;

	info->type = **format;
	get_f(&number, info);
	specs_handler(info);
	data.str = ft_ftoa_static(number, info->precision);
	data.length = ft_strlen(data.str);
	data.negative = 0;
	apply_specs(info, &data);
}
