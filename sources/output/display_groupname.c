/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_groupname.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:13:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/02 18:11:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_groupname(const char *groupname, size_t width)
{
	ft_printf("  %-*s", width, groupname);
}
