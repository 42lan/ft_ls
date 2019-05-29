/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 10:26:29 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/20 16:27:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		write_order(t_info *info, t_data *data)
{
	if (info->minus == 0)
	{
		if (info->zero == 0)
			while (info->width-- > 1)
				write_char(&info->buffer, ' ');
		else
			while (info->width-- > 1)
				write_char(&info->buffer, '0');
		write_char(&info->buffer, *data->str);
	}
	else
	{
		write_char(&info->buffer, *data->str);
		if (info->zero == 0)
			while (info->width-- > 1)
				write_char(&info->buffer, ' ');
		else
			while (info->width-- > 1)
				write_char(&info->buffer, '0');
	}
}

static void		specs_handler(t_info *info)
{
	info->hash = 0;
	info->plus = 0;
	info->space = 0;
	info->precision = 0;
}

void			type_c(const char **format, t_info *info)
{
	char		c;
	t_data		data;

	info->type = **format;
	c = (char)va_arg(info->ap, int);
	data.str = &c;
	if (c == 0)
	{
		write_order(info, &data);
		return ;
	}
	data.length = 1;
	data.negative = 0;
	specs_handler(info);
	apply_specs(info, &data);
}
