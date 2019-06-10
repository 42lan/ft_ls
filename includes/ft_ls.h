/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:53:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/09 16:19:13 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <errno.h>
# include <dirent.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include <uuid/uuid.h>
# include "../libft/includes/libft.h"

typedef struct		s_file
{
	struct s_file	*next;
}					t_file;

int					ft_ls(int ac, char **av);
int					ft_listdir(const char *path);

#endif
