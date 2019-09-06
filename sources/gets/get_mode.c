/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 13:45:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/06 13:54:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_mode(mode_t st_mode)
{
	char	*str;

	str = ft_memalloc(12);
	str[0] = get_type(st_mode);
	ft_strcat(str, get_permissions(st_mode, 0));
	ft_strcat(str, get_permissions(st_mode, 3));
	ft_strcat(str, get_permissions(st_mode, 6));
	set_special_permissions(st_mode, &str);
	//set_extended_attributes();
	str[10] = (S_ISLNK(st_mode)) ? '@' : ' ';
	return (str);
}
