/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:35:13 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/28 11:40:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_perror_exit() performs normal termination of process.
**
** EXIT_FAILURE is the standard value for returning unsuccessful termination
** defined it stdlib.h.
*/

void	ft_perror_exit(const char *s)
{
	ft_perror(s);
	exit(EXIT_FAILURE);
}
