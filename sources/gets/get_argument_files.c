/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 14:27:39 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/30 09:55:48 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dir			*get_argument_files(int argc, char **argv)
{
	int			i;
	t_dir		*directory;
	t_file		*file;

	i = 0;
	directory = new_directory(NULL);
	while (is_option(argv[++i]))
		if (ft_strequ(argv[i], "--"))
		{
			i++;
			break ;
		}
	if (argv[i] == NULL)
		directory->file_head = new_file(NULL, ".");
	else
		while (i < argc)
		{
			if (ft_strequ(argv[i], ""))
				print_fts_open();
			file = new_file(NULL, argv[i]);
			append_file(&directory, file);
			i++;
		}
	return (directory);
}
