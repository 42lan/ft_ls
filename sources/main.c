/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:51:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/30 10:22:31 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_argp		g_argp[] =
{
	{'A', 0, "List all entries except for . and .."},
	{'F', 0, "Append indicator (one of */=@|)"},
	{'R', 0, "Recursively list subdirectories encountered"},
	{'T', 0, "Diplay complete time information in long format"},
	{'a', 0, "List files whose names begin with a dot (.)"},
	{'g', 0, "List in long format without owner information"},
	{'l', 0, "List in long format"},
	{'n', 0, "List in long format numeric user and group IDs"},
	{'o', 0, "List in long format without group information"},
	{'p', 0, "Append / indicator to directories"},
	{'r', 0, "Reverse the order of the sort"},
	{'t', 0, "Sort by time modified (most recently modified first)"},
	{'1', 0, "List one file per line"},
	{0, 0, NULL}
};

int			main(int argc, char **argv)
{
	t_dir	*directory;

	get_options(argc, argv);
	directory = get_argument_files(argc, argv);
	ft_mergesort(&directory->file_head, &name_cmp);
	check_accessibility(&directory->file_head);
	if (directory->file_head != NULL)
		lineup_files(&directory->file_head);
	ft_ls(directory);
	return (0);
}
