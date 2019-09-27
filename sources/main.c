/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:51:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/27 17:53:21 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_argp		g_argp[] =
{
	{'A', 0, "List all entries except for . and .."},
	{'F', 0, "Append indicator (one of */=@|)"},
	{'R', 0, "Recursively list subdirectories encountered"},
	{'a', 0, "List files whose names begin with a dot (.)"},
	{'f', 0, "Unsorted output"},
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
	t_file	*file_list;

	get_options(argc, argv);
	file_list = get_argument_files(argc, argv);
	if (g_argp[UNSORTED].active == 0)
		ft_mergesort(&file_list, &name_cmp);
	check_accessibility(&file_list);
	if (file_list != NULL)
		lineup_files(&file_list);
	ft_ls(file_list);
	return (0);
}
