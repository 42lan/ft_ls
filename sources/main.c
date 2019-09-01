/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:51:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/01 19:46:35 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_argp			g_argp[] =
{
	{'l', 0, "List in long format"},
	{'a', 0, "List files whose names begin with a dot (.)"},
	{'R', 0, "Recursively list subdirectories encountered"},
	{'r', 0, "Reverse the order of the sort"},
	{'1', 0, "List one file per line"},
	{'t', 0, "Sort by time modified (most recently modified first)"},
	{0, 0, NULL}
};

void			print_argument_files(t_file *head)
{
	while (head)
	{
		if (head->next != NULL)
			ft_printf("%s --> ", head->name, head->next->name);
		else
			ft_printf("%s --> NULL\n", head->name);
		head = head->next;
	}
}

int				main(int ac, char **av)
{
	t_file		*file_list;

	get_options(ac, av);
	file_list = get_argument_files(ac, av);
	ft_mergesort(&file_list, &name_cmp);
	check_accessibility(&file_list);
	ft_ls(file_list);
	return (0);
}
