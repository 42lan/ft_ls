/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:27:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/02 15:21:36 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*get_argument_files(int ac, char **av)
{
	int			i;
	t_file		*file;
	t_file		*head;

	i = 1;
	head = NULL;
	while (is_option(av[i]))
		i++;
	if (av[i] == NULL)
		head = new_file(".", NULL);
	else
		while (i < ac)
		{
			file = new_file(av[i], NULL);
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
