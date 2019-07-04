/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_nlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:05:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 07:42:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_nlink(nlink_t st_nlink, int width)
{
	(void)width;
	ft_printf("%d\n", width);
	ft_printf("%*d. ", width, st_nlink);
}
