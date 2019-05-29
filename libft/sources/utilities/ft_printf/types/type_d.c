/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:03:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/21 17:11:05 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		specs_handler(t_info *info, t_data *data, intmax_t number)
{
	if ((data->length == 1 && info->space == 0 && info->plus == 0)
		|| info->hash == 1)
		info->zero = 0;
	if ((((info->plus | info->space) & 1) && data->negative == 0)
		|| number < 0)
		info->width--;
	info->hash = 0;
}

void			type_d(const char **format, t_info *info)
{
	intmax_t	number;
	t_data		data;

	info->type = **format;
	get_si(&number, info);
	if (number == 0 && info->point == 1 && info->precision == 0)
		data.str = (info->width != 0) ? " " : "\0";
	else
		data.str = (ft_islower(info->type) && info->length == 0)
					? ft_sitoa_base_static(ABS(number), 10, 0)
					: ft_uitoa_base_static(ABS(number), 10, 0);
	data.length = ft_strlen(data.str);
	data.negative = (number < 0) ? 1 : 0;
	specs_handler(info, &data, number);
	apply_specs(info, &data);
}
