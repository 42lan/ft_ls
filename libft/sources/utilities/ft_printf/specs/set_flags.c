/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 05:00:15 by amalsago          #+#    #+#             */
/*   Updated: 2019/05/21 18:37:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Below are the functions that sets (and unsets) corresponding (ignored) flag.
*/

void	flag_space(const char **format, t_info *info)
{
	info->space = 1;
	(*format)++;
}

void	flag_hash(const char **format, t_info *info)
{
	info->hash = 1;
	(*format)++;
}

void	flag_plus(const char **format, t_info *info)
{
	info->plus = 1;
	info->space = 0;
	(*format)++;
}

void	flag_minus(const char **format, t_info *info)
{
	info->minus = 1;
	info->zero = 0;
	(*format)++;
}

void	flag_zero(const char **format, t_info *info)
{
	info->zero = 1;
	(*format)++;
}
