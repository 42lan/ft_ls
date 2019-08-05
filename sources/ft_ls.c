/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/05 12:02:11 by amalsago         ###   ########.fr       */
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
	{'-', 0, "End of options"},
	{0, 0, NULL}
};

void	print_opt(t_argp g_argp[])
{
	ft_putendl("SETTED OPTION ARE:\n");
	int	i = -1;
	while (g_argp[++i].sign)
		ft_printf("%c %d\n", g_argp[i].sign, g_argp[i].active);
}

int				ft_ls(int ac, char **av)
{
	int			i;
	t_file		*file;

	i = -1;
	if (ac == 0)
		browse_dir(".");
	else
	{
		while (++i < ac)
		{
			if (av[i][0] == '-')
			{
				parse_argp(av[i]);
				if (av[i + 1] == NULL)
					browse_dir(".");
				continue ;
			}
			file = new_file();
			file->stat = get_stat(av[i]);
			if (is_directory(file->stat->st_mode))
			{
				free(file);
				file = NULL;
				browse_dir(av[i]);
			}
			else
				browse_file(av[i], file);
		}
	}
	return (1);
}
