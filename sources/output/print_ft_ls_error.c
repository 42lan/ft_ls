/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_ls_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:52:38 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/28 11:51:10 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_ft_ls_error(const char *filename, int errnum)
{
	ft_perror("ls: ");
	ft_perror(filename);
	ft_perror(": ");
	ft_perror(strerror(errnum));
}
