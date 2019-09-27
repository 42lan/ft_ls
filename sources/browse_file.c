/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   browse_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:46:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 11:24:40 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern t_argp		g_argp[];

void				browse_file(const char *filename)
{
	t_file			*file;
	t_dir			*directory;

	file = new_file(NULL, filename);
	directory = new_directory(NULL);
	fill_struct(file);
	directory->nb_files = 1;
	directory->file_head = file;
	determine_wmax(directory->wmax, file);
	display(directory);
}
