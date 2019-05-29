/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:11:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/20 12:15:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			type_u(const char **format, t_info *info)
{
	uintmax_t	number;
	t_data		data;

	info->type = **format;
	info->hash = 0;
	get_ui(&number, info);
	data.str = ft_uitoa_base_static(number, 10, 0);
	data.length = (number == 0 && info->width == 0 && info->point == 1
					&& info->precision == 0) ? 0 : ft_strlen(data.str);
	data.negative = 0;
	apply_specs(info, &data);
}
