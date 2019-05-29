/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_si.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:05:06 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/21 17:02:28 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_si() retrieves a signed integer from arguments depending on what type
** of length was specified (which bit is setted to 1).
*/

void	get_si(intmax_t *number, t_info *info)
{
	if (ft_isupper(info->type) || info->length & (LENGTH_J | LENGTH_LL))
		*number = (intmax_t)va_arg(info->ap, intmax_t);
	else if (info->length == 0 || info->length & LENGTH_T)
		*number = (int)va_arg(info->ap, int);
	else if (info->length & LENGTH_H)
		*number = (short int)va_arg(info->ap, int);
	else if (info->length & LENGTH_HH)
		*number = (signed char)va_arg(info->ap, int);
	else if (info->length & LENGTH_L)
		*number = (long int)va_arg(info->ap, long int);
	else if (info->length & LENGTH_Z)
		*number = (size_t)va_arg(info->ap, size_t);
}
