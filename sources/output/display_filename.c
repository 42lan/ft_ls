/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_filename.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:18:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/12 15:45:59 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	display_filename(char *filename, int namlen, int width)
{
	ft_printf("%*s\n", namlen + width, filename);
}
