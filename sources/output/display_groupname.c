/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_groupname.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:13:33 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 06:02:42 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_groupname(char *groupname, size_t width)
{
	ft_printf("%*s", width + 2, groupname);
}
