/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:01:08 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/21 17:01:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_si() retrieves a unsigned integer from arguments depending on what type
** of length was specified (which bit is setted to 1).
*/

void	get_ui(uintmax_t *number, t_info *info)
{
	if ((info->length == 0 || info->length & LENGTH_T)
		&& (info->type != 'O' && info->type != 'U'))
		*number = (unsigned int)va_arg(info->ap, unsigned int);
	else if ((ft_isupper(info->type) && info->type != 'X')
			|| info->length & (LENGTH_LL | LENGTH_J))
		*number = (uintmax_t)va_arg(info->ap, uintmax_t);
	else if (info->length & LENGTH_H)
		*number = (unsigned short int)va_arg(info->ap, int);
	else if (info->length & LENGTH_HH)
		*number = (unsigned char)va_arg(info->ap, int);
	else if (info->length & LENGTH_L)
		*number = (unsigned long int)va_arg(info->ap, unsigned long int);
	else if (info->length & LENGTH_Z)
		*number = (size_t)va_arg(info->ap, size_t);
}
