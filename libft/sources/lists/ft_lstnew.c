/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:31:48 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:02:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns a “fresh” link. The variables content and content_size
** of the new link are initialized by copy of the parameters of the function.
** If the parameter content is NULL, the variable content is initialized to NULL
** and the variable content_size is initialized to 0 even if the parameter
** content_size isn’t. The variable next is initialized to NULL.
** If the allocation fails, the function returns NULL.
*/

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = ft_memalloc(content_size)))
		{
			free(list);
			list = NULL;
			return (NULL);
		}
		ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
