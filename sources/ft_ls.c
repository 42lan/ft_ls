/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/03 14:42:52 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_ls(t_file *head)
{
	//t_file	*regular = head;
	//t_file	*directory = head;

	/*
	while (regular)
	{
		if (S_ISREG(regular->stat->st_mode))
			browse_file(regular->name, regular);
		regular = regular->next;
	}
	ft_printf("\n");
	while (directory)
	{
		if (S_ISDIR(directory->stat->st_mode))
			browse_dir(directory->name);
		directory = directory->next;
	}
	*/
	t_file	*curr = head;
	t_file	*next = NULL;
	t_file	*reglst = NULL;
	t_file	*dirlst = NULL;
	t_file	*lastdir = NULL;
	t_file	*lastreg = NULL;
	while (curr)
	{
		next = curr->next;
		if (S_ISDIR(curr->stat->st_mode))
		{
			if (dirlst == NULL)
			{
				dirlst = curr;
				curr = next;
				lastdir = dirlst;
				lastdir->next = NULL;
			}
			else
			{
				lastdir->next = curr;
				lastdir = curr;
				lastdir->next = NULL;
				curr = next;
			}
		}
		else if (S_ISREG(curr->stat->st_mode))
		{
			if (reglst == NULL)
			{
				reglst = curr;
				curr = next;
				lastreg = reglst;
				lastreg->next = NULL;
			}
			else
			{
				lastreg->next = curr;
				lastreg = curr;
				lastreg->next = NULL;
				curr = next;
			}
		}
	}
	lastreg->next = dirlst;
	head = reglst;
	while (head)
	{
		if (head->next == NULL)
			ft_printf("%s -> NULL\n", head->name);
		else
			ft_printf("%s -> ", head->name);
		head = head->next;
	}
	return (1);
}
