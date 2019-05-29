/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:08:31 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/21 16:20:00 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_f() retrieves a floating number from arguments.
** If length 'L' was specified it retrieves a long double, otherwise double.
*/

void	get_f(long double *number, t_info *info)
{
	if (info->length & LENGTH_LLL)
		*number = (long double)va_arg(info->ap, long double);
	else
		*number = (double)va_arg(info->ap, double);
}
