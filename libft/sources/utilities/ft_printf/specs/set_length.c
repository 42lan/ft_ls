/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:04:35 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/21 18:37:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Below are the functions that sets corresponding length of a placeholder.
*/

void	length_h(const char **format, t_info *info)
{
	if (info->length == 0)
	{
		info->length = LENGTH_H;
		if (*(*format + 1) == 'h')
		{
			info->length = LENGTH_HH;
			(*format)++;
		}
	}
	(*format)++;
}

void	length_l(const char **format, t_info *info)
{
	if (**format == 'L')
		info->length = LENGTH_LLL;
	else
	{
		info->length = LENGTH_L;
		if (*(*format + 1) == 'l')
		{
			info->length = LENGTH_LL;
			(*format)++;
		}
	}
	(*format)++;
}

void	length_j(const char **format, t_info *info)
{
	info->length = LENGTH_J;
	(*format)++;
}

void	length_z(const char **format, t_info *info)
{
	info->length = LENGTH_Z;
	(*format)++;
}

void	length_t(const char **format, t_info *info)
{
	info->length = LENGTH_T;
	(*format)++;
}
