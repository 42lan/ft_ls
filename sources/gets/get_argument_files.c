/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:27:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 12:46:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*get_argument_files(int argc, char **argv)
{
	int			i;
	t_file		*head;
	t_file		*file;

	i = 1;
	head = NULL;
	while (is_option(argv[i]))
	{
		if (ft_strequ(argv[i], "--"))
		{
			i++;
			break ;
		}
		i++;
	}
	if (argv[i] == NULL)
		head = new_file(NULL, ".");
	else
		while (i < argc)
		{
			file = new_file(NULL, argv[i]);
			if (head == NULL)
				head = file;
			else
			{
				file->next = head;
				head = file;
			}
			i++;
		}
	return (head);
}
