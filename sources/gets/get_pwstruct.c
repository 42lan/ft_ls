/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwstruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:29:32 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/13 09:33:14 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct passwd		*get_pwstruct(uid_t st_uid)
{
	struct passwd	*passwd;

	if (!(passwd = (struct passwd *)malloc(sizeof(struct passwd))))
		return (NULL);
	passwd = getpwuid(st_uid);
	return (passwd);
}
