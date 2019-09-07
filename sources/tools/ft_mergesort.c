/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:20:32 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/06 16:53:44 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		frontbacksplit(t_file *source, t_file **frontref,
				t_file **backref)
{
	t_file		*fast;
	t_file		*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*frontref = source;
	*backref = slow->next;
	slow->next = NULL;
}

static t_file	*sortedmerge(t_file *a, t_file *b,
				int (*cmp)(t_file *, t_file *))
{
	t_file		*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (cmp(a, b) <= 0)
	{
		result = a;
		result->next = sortedmerge(a->next, b, cmp);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next, cmp);
	}
	return (result);
}

void			ft_mergesort(t_file **headref, int (*cmp)(t_file *, t_file *))
{
	t_file		*a;
	t_file		*b;
	t_file		*head;

	head = *headref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	frontbacksplit(head, &a, &b);
	ft_mergesort(&a, cmp);
	ft_mergesort(&b, cmp);
	*headref = sortedmerge(a, b, cmp);
}
