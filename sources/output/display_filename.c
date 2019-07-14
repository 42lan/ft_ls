/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:18:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/14 07:11:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_filename(char *filename, size_t width)
{
	ft_printf("%*s", width, filename);
}
