/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:35:13 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/22 12:44:04 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_error_exit() perform normal termination of process.
**
** EXIT_FAILURE is the standard value for returning unsuccessful termination
** defined it stdlib.h.
*/

void	ft_error_exit(const char *error)
{
	ft_strerror(error);
	exit(EXIT_FAILURE);
}
