/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:52:38 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/28 11:44:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_error(const char *filename, int errnum)
{
	ft_print_error("ls: ");
	ft_print_error(filename);
	ft_print_error(": ");
	ft_print_error(strerror(errnum));
	ft_print_error("\n");
}
