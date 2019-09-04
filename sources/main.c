/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:51:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/04 13:36:55 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_argp			g_argp[] =
{
	{'l', 0, "List in long format"},
	{'R', 0, "Recursively list subdirectories encountered"},
	{'a', 0, "List files whose names begin with a dot (.)"},
	{'r', 0, "Reverse the order of the sort"},
	{'t', 0, "Sort by time modified (most recently modified first)"},
	{'1', 0, "List one file per line"},
	{0, 0, NULL}
};

int			main(int ac, char **av)
{
	t_file	*file_list;

	get_options(ac, av);
	file_list = get_argument_files(ac, av);
	ft_mergesort(&file_list, &name_cmp);
	check_accessibility(&file_list);
	if (file_list != NULL)
		lineup_files(&file_list);
	ft_ls(file_list);
	return (0);
}
