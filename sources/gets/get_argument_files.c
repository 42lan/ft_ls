/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:27:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 12:09:46 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		append_to_head(t_file **head, t_file *file)
{
	if ((*head) == NULL)
		(*head) = file;
	else
	{
		file->next = (*head);
		(*head) = file;
	}
}

t_file			*get_argument_files(int argc, char **argv)
{
	int			i;
	t_file		*head;
	t_file		*file;

	i = 0;
	head = NULL;
	while (is_option(argv[++i]))
		if (ft_strequ(argv[i], "--"))
		{
			i++;
			break ;
		}
	if (argv[i] == NULL)
		head = new_file(NULL, ".");
	else
		while (i < argc)
		{
			if (ft_strequ(argv[i], ""))
				print_fts_open();
			file = new_file(NULL, argv[i]);
			append_to_head(&head, file);
			i++;
		}
	return (head);
}
