/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:18:56 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 10:01:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Iterates a list lst and applies the function f to each link to create a
** “fresh” list resulting from the successive applications of f.
** If the allocation fails, the function returns NULL.
*/

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	**tmp;

	if (!lst || !f)
		return (NULL);
	newlst = f(lst);
	tmp = &newlst;
	while (lst)
	{
		*tmp = f(lst);
		tmp = &(*tmp)->next;
		lst = lst->next;
	}
	return (newlst);
}
