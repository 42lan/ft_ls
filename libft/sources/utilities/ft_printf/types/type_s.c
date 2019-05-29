/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 14:37:54 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/19 15:39:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_width_s(t_info *info, t_data *data)
{
	if (data->str != 0)
	{
		if ((info->width >= data->length && info->point == 0)
			|| (info->width != 0 && info->precision > data->length))
			info->width -= data->length;
		else if ((info->width != 0 && (data->length == 0
				|| (info->point == 0 || info->precision == 0))))
			info->width = info->width;
		else if (info->width != 0 && info->precision <= data->length)
			info->width -= info->precision;
	}
	if (info->zero == 0)
		while (info->width-- > 0)
			write_char(&info->buffer, ' ');
	else
		while (info->width-- > 0)
			write_char(&info->buffer, '0');
}

static void		write_order(t_info *info, t_data *data)
{
	if (info->minus == 0)
	{
		put_width_s(info, data);
		write_str(&info->buffer, data->str, data->length);
	}
	else
	{
		write_str(&info->buffer, data->str, data->length);
		put_width_s(info, data);
	}
}

static void		data_null(t_info *info, t_data *data)
{
	if (info->zero == 0)
		info->width = 0;
	data->str = "(null)";
	data->length = ft_strlen(data->str);
	if (info->point == 1)
	{
		if (info->precision == 0)
			data->length = 0;
		else if (info->precision > 0)
			data->length = info->precision;
	}
	write_order(info, data);
}

static void		specs_handler(t_info *info)
{
	info->hash = 0;
	info->plus = 0;
	if (info->minus == 1)
		info->zero = 0;
}

void			type_s(const char **format, t_info *info)
{
	t_data		data;

	info->type = **format;
	specs_handler(info);
	data.str = va_arg(info->ap, char *);
	if (data.str == NULL)
	{
		data_null(info, &data);
		return ;
	}
	data.length = ft_strlen(data.str);
	if (info->point == 1)
	{
		if (info->precision == 0)
			data.length = 0;
		else if (info->precision < data.length)
			data.length = info->precision;
	}
	write_order(info, &data);
}
