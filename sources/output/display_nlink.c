/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:05:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/06 13:42:02 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_nlink(nlink_t st_nlink, int width)
{
	ft_printf("%*d", width + 1, st_nlink);
}
