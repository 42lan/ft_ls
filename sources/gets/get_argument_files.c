/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:27:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/09 10:57:24 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*get_argument_files(int ac, char **av)
{
	int			i;
	t_file		*head;
	t_file		*file;

	i = 1;
	head = NULL;
	while (is_option(av[i]))
		i++;
	if (av[i] == NULL)
		head = new_file(NULL, ".");
	else
		while (i < ac)
		{
			file = new_file(NULL, av[i]);
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
