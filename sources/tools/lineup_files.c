/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lineup_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:03:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/04 17:26:43 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		update_head(t_file **head, t_file *dirlst, t_file *reglst, t_file *lastreg)
{
	if (lastreg == NULL)
		*head = dirlst;
	else
	{
		lastreg->next = dirlst;
		*head = reglst;
	}
}

void			lineup_files(t_file **head)
{
	t_file		*curr;
	t_file		*next;
	t_file		*reglst;
	t_file		*dirlst;
	t_file		*lastdir;
	t_file		*lastreg;

	curr = *head;
	reglst = NULL;
	dirlst = NULL;
	lastdir = NULL;
	lastreg = NULL;
	if (curr->next != NULL)
	{
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
		update_head(head, dirlst, reglst, lastreg);
	}
}
/*
static void		update_head(t_file **head, t_file *dirlst, t_file *reglst, t_file *lastreg)
{
	if (lastreg == NULL)
		*head = dirlst;
	else
	{
		lastreg->next = dirlst;
		*head = reglst;
	}
}

static void		dir_handler(t_file **dirlst, t_file **curr, t_file **lastdir, t_file *next)
{
	if ((*dirlst) == NULL)
	{
		(*dirlst) = (*curr);
		(*curr) = next;
		(*lastdir) = (*dirlst);
		(*lastdir)->next = NULL;
	}
	else
	{
		(*lastdir)->next = (*curr);
		(*lastdir) = (*curr);
		(*lastdir)->next = NULL;
		(*curr) = next;
	}
}

static void		reg_handler(t_file **reglst, t_file **curr, t_file **lastreg, t_file *next)
{
	if ((*reglst) == NULL)
	{
		(*reglst) = (*curr);
		(*curr) = next;
		(*lastreg) = (*reglst);
		(*lastreg)->next = NULL;
	}
	else
	{
		(*lastreg)->next = (*curr);
		(*lastreg) = (*curr);
		(*lastreg)->next = NULL;
		(*curr) = next;
	}
}

void			lineup_files(t_file **head)
{
	t_file		*curr;
	t_file		*next;
	t_file		*reglst;
	t_file		*dirlst;
	t_file		*lastdir;
	t_file		*lastreg;

	curr = *head;
	reglst = NULL;
	dirlst = NULL;
	lastdir = NULL;
	lastreg = NULL;
	if (curr->next != NULL)
	{
		while (curr)
		{
			next = curr->next;
			if (S_ISDIR(curr->stat->st_mode))
				dir_handler(&dirlst, &curr, &lastdir, next);
			else if (S_ISREG(curr->stat->st_mode))
				reg_handler(&reglst, &curr, &lastreg, next);
		}
		update_head(head, dirlst, reglst, lastreg);
	}
}
*/
