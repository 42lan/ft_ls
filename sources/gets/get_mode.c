/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:45:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/05 18:45:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_mode(mode_t st_mode)
{
	char	*str;

	str = ft_memalloc(10);
	str[0] = get_type(st_mode);
	ft_strcat(str, get_permissions(st_mode, 0));
	ft_strcat(str, get_permissions(st_mode, 3));
	ft_strcat(str, get_permissions(st_mode, 6));
	set_special_permissions(st_mode, &str);
	return (str);
}
