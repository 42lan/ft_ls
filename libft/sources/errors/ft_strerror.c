/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:36:32 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/22 12:38:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strerror(const char *error)
{
	if (!error)
		ft_putstr_fd("Unknown error\n", STDERR_FILENO);
	else
		ft_putstr_fd(error, STDERR_FILENO);
}
