/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:50:47 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:02:08 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter the adress of a pointer to a link and frees the memory
** of this link and every successors of that link using the functions del and
** free(3). Finally the pointer to the link that was just freed is setted to
** NULL.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && del)
	{
		while (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			(*alst) = (*alst)->next;
		}
	}
}
