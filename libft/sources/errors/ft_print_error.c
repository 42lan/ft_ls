/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:36:32 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/28 11:38:39 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_error(const char *error)
{
	if (!error)
		ft_putstr_fd("Unknown error\n", STDERR_FILENO);
	else
		ft_putstr_fd(error, STDERR_FILENO);
}
