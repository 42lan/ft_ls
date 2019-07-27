/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/27 18:49:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_argp			g_argp[] =
{
	{'1', 0, "List one file per line"},
	{'l', 0, "List in long format"},
	{'R', 0, "Recursively list subdirectories encountered"},
	{'a', 0, "List files whose names begin with a dot (.)"},
	{'r', 0, "Reverse the order of the sort"},
	{'t', 0, "Sort by time modified (most recently modified first)"},
	{'-', 0, "End of options"},
	{0, 0, NULL}
};

int				ft_ls(int ac, char **av)
{
	int			i;
	t_file		*file;

	i = -1;
	if (ac == 0)
		browse_dir(".");
	else
	{
		parse_argp(ac, av, g_argp);
		if (g_argp[1].active == 1)
		{
			ft_printf("OKOKOK\n");
			return (1);
		}
		while (++i < ac)
		{
			file = new_file();
			file->stat = get_stat(av[i]);
			if (is_directory(file->stat->st_mode))
			{
				free(file); file = NULL;
				browse_dir(av[i]);
			}
			else
				browse_file(av[i], file);
		}
	}
	return (1);
}
