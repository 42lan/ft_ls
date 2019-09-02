/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse_recursive.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 12:56:52 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/02 13:04:51 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Time complexity: O(n)
** Space complexity: O(n)
*/

t_list			*ft_lstreverse_recursive(t_list *head)
{
	t_list		*rest;

	if (head == NULL || head->next == NULL)
		return (head);
	rest = ft_lstreverse_recursive(head->next);
	head->next->next = head;
	head->next = NULL;
	head = rest;
	return (head);
}
