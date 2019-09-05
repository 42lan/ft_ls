/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_special_permissions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:41:43 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/05 18:42:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		set_suid(char **str)
{
	if ((*str)[3] == 'x')
		(*str)[3] = 's';
	else if ((*str)[3] == '-')
		(*str)[3] = 'S';
}

static void		set_sgid(char **str)
{
	if ((*str)[6] == 'x')
		(*str)[6] = 's';
	else if ((*str)[6] == '-')
		(*str)[6] = 'S';
}

static void		set_stickybit(char **str)
{
	if ((*str)[9] == 'x')
		(*str)[9] = 't';
	else if ((*str)[9] == '-')
		(*str)[9] = 'T';
}

void			set_special_permissions(mode_t st_mode, char **str)
{
	if (st_mode & S_ISUID)
		set_suid(str);
	if (st_mode & S_ISGID)
		set_sgid(str);
	if (st_mode & S_ISVTX)
		set_stickybit(str);
}
