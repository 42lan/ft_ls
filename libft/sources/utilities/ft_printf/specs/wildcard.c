/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 15:14:26 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/21 18:46:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** wildcard() handle asterisk '*' so that width and/or precision fields might
** be omitted, or a numeric integer value, or a dynamic value when passed as
** another argument.
*/

void			wildcard(const char **format, t_info *info)
{
	if (*(*format - 1) != '.')
	{
		info->width = va_arg(info->ap, int);
		if (info->width < 0)
		{
			info->minus = 1;
			info->width *= -1;
		}
	}
	else
		info->precision = va_arg(info->ap, int);
	(*format)++;
}
