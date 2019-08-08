/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:12:50 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/08 13:23:38 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

static void		mtime_sort(t_file *head)
{
	(void)head;

}

static int		alpha_sort(t_file *head)
{
	t_file		*i;
	t_file		*j;
	char		*tmp;

	if (head == NULL)
		return (0);
	i = head;
	while (i->next != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (ft_memcmp(i->name, j->name, sizeof(char *)) > 0)
			{
				tmp = i->name;
				i->name = j->name;
				j->name = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

void			sort_files(t_file *file_head)
{
	if (g_argp[MTIME_SORT].sign == 1)
		mtime_sort(file_head);
	else
		alpha_sort(file_head);
}
