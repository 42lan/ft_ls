/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/02 15:28:41 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_ls(t_file *head)
{
	t_file	*file;

	file = head;
	while (file)
	{
		if (S_ISDIR(file->stat->st_mode))
		{
			ft_printf("%s:\n", file->name);
			browse_dir(file->name);
			if (file->next != NULL)
				ft_putchar('\n');
		}
		else
			browse_file(file->name, file);
		file = file->next;
	}
	/*
	if (ac == 0)
		browse_dir(".");
	else
	{
		get_options(&av);
		if (*av == NULL)
			browse_dir(".");
		else
		{
			arg_files = get_files_from_arguments(av);
			print_arg_files(arg_files);
			sort_arg_files(arg_files);
			while (++i < ac)
			{
				file = new_file();
				if (get_stat(av[i], file) == 0)
				{
					ft_printf("Error get_stat(%s)\n", av[i]);
					exit(0);
				}
				if (S_ISDIR(file->stat->st_mode))
				{
					free(file);
					file = NULL;
					browse_dir(av[i]);
				}
				else
					browse_file(av[i], file);
			}
		}
	}
	*/
	return (1);
}
