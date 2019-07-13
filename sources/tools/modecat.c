/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modecat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:45:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/12 02:44:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	modecat(char *str, mode_t st_mode)
{
	str[0] = get_type(st_mode);
	ft_strcat(str, get_permissions(st_mode, 0));
	ft_strcat(str, get_permissions(st_mode, 3));
	ft_strcat(str, get_permissions(st_mode, 6));
	str[10] = '\0';
}
