/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:45:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/23 13:54:49 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_modes(char *modes_str, mode_t mode)
{
	strcat(modes_str, ft_get_permissions(mode, 0));
	strcat(modes_str, ft_get_permissions(mode, 3));
	strcat(modes_str, ft_get_permissions(mode, 6));
	modes_str[9] = '\0';
}
