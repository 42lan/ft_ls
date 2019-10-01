/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_special_permissions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:41:43 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/01 14:29:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		set_suid(char **mode)
{
	if ((*mode)[3] == 'x')
		(*mode)[3] = 's';
	else if ((*mode)[3] == '-')
		(*mode)[3] = 'S';
}

static void		set_sgid(char **mode)
{
	if ((*mode)[6] == 'x')
		(*mode)[6] = 's';
	else if ((*mode)[6] == '-')
		(*mode)[6] = 'S';
}

static void		set_stickybit(char **mode)
{
	if ((*mode)[9] == 'x')
		(*mode)[9] = 't';
	else if ((*mode)[9] == '-')
		(*mode)[9] = 'T';
}

void			set_special_permissions(mode_t st_mode, char *mode)
{
	if (st_mode & S_ISUID)
		set_suid(&mode);
	if (st_mode & S_ISGID)
		set_sgid(&mode);
	if (st_mode & S_ISVTX)
		set_stickybit(&mode);
}
