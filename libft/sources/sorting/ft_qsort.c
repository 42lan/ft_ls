/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:46:40 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/09 16:25:34 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_partition(char **array, int left, int right)
{
	char		*pivot;
	int			start;
	int			end;

	pivot = array[left];
	start = left;
	end = right;
	while (start < end)
	{
		while (ft_strcmp(array[start], pivot) <= 0  && start < end)
			start++;
		while (ft_strcmp(array[end], pivot) > 0)
			end--;
		if (start < end)
			ft_swap(&array[start], &array[end], sizeof(char));
	}
	array[left] = array[end];
	array[end] = pivot;
	return (end);
}

void			ft_qsort(char **array, int left, int right)
{
	int			pivot_location;

	if (left < right)
	{
		pivot_location = ft_partition(array, left, right);
		ft_qsort(array, left, pivot_location - 1);
		ft_qsort(array, pivot_location + 1, right);
	}
}
