/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:53:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/23 14:09:19 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <errno.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include <uuid/uuid.h>
# include "../libft/includes/libft.h"
# include "colors.h"

typedef struct		s_dir
{
	DIR				*dp;
	struct dirent	*de;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_entry
{
	char			*name;
	int				length;
	time_t			timestamp;
	struct stat		stat;
	struct passwd	*passwd;
	struct group	*group;
	struct s_file	*next;
}					t_entry;

int					ft_ls(int ac, char **av);
void				ft_list_dir(char *entryname);
int					ft_inspect_entry(t_entry *entry, char *path);
char				*ft_get_permissions(mode_t mode, int ugo);
void				ft_modes(char *modes_str, mode_t mode);
char				ft_type(mode_t mode);

#endif
