/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:02:03 by amalsago          #+#    #+#             */
/*   Updated: 2019/08/19 18:25:22 by amalsago         ###   ########.fr       */
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

void	print_opt(t_argp g_argp[])
{
	int	i;

	i = -1;
	while (g_argp[++i].sign)
		ft_printf("%c ", g_argp[i].sign);
	ft_putchar('\n');
	i = -1;
	while (g_argp[++i].sign)
		ft_printf("%d ", g_argp[i].active);
	ft_putchar('\n');
}

void        print_av(char **av)
{
	while (*av)
	{
		printf("%s, ", *av);
		av++;
	}
	printf("%s\n", *av);
}

void			sort_arguments(char **av)
{
	t_list		*head;
	t_list		*node;

	head = NULL;
	node = NULL;
	while (*av)
	{
		if (head == NULL)
			head = ft_lstnew(*av, ft_strlen(*av) + 1);
		else
		{
			node = ft_lstnew(*av, ft_strlen(*av) + 1);
			ft_lstadd_end(&head, node);
		}
		av++;
	}
	ft_lstprint(head);
	ft_lstreverse(head);
	ft_lstprint(head);
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
		get_options(&av);
		//		sort_arguments(av);
		if (*av == NULL)
			browse_dir(".");
		else
		{
			while (++i < ac - 1)
			{
				file = new_file();
				if (get_stat(av[i], file) == 0)
				{
					ft_printf("Error get_stat(%s)\n", av[i]);
					exit(0);
				}
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
	}
	return (1);
}
