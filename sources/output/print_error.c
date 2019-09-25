/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:52:38 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/25 09:57:32 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_error(const char *filename, int errnum)
{
	ft_strerror("ft_ls: ");
	ft_strerror(filename);
	ft_strerror(": ");
	ft_strerror(strerror(errnum));
	ft_strerror("\n");
}
