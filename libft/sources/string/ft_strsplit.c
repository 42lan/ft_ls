/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 08:02:34 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/20 11:58:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates and returns an array of “fresh” strings (all ending with ’\0’,
** including the array itself) obtained by splitings using the characterc as a
** delimiter. If the allocation fails the function returns NULL.
*/

static int			ft_wordlen(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && !(ft_isseparator(s[i], c)))
		i++;
	return (i);
}

static char			*ft_storeword(char const *s, char c)
{
	unsigned int	i;
	char			*tmp;

	i = -1;
	if (!(tmp = ft_strnew(ft_wordlen(s, c))))
		return (NULL);
	while (s[++i] != '\0' && !(ft_isseparator(s[i], c)))
		tmp[i] = s[i];
	return (tmp);
}

char				**ft_strsplit(char const *s, char c)
{
	unsigned int	words;
	unsigned int	nofword;
	char			**tab;

	if (!s)
		return (NULL);
	nofword = 0;
	words = ft_count_words(s, c);
	if (!(tab = ft_strnew2d(words)))
		return (NULL);
	while (*s != '\0')
	{
		if (!(ft_isseparator(*s, c)))
		{
			if (!(tab[nofword] = ft_storeword(s, c)))
				return (NULL);
			nofword++;
			while (*s != '\0' && !ft_isseparator(*s, c))
				s++;
		}
		else
			s++;
	}
	tab[nofword] = 0;
	return (tab);
}
