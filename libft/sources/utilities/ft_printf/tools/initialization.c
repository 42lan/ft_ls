/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:22:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/20 16:21:12 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_buffer(t_buffer *buffer)
{
	buffer->index = 0;
	buffer->length = 0;
}

void	initialize_specs(t_info *info)
{
	info->width = 0;
	info->length = 0;
	info->precision = 0;
	initialize_flags(info);
}

void	initialize_flags(t_info *info)
{
	info->hash = 0;
	info->zero = 0;
	info->plus = 0;
	info->minus = 0;
	info->space = 0;
	info->point = 0;
}
