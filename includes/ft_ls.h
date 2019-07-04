/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:53:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/04 07:28:49 by amalsago         ###   ########.fr       */
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
	char			*name;			// Current directory name
	size_t			length;			// Length of current directory
	char			*parent_name;			// Parent name of current directory
	char			*fullpath;
	char			*ownername;
	size_t			ownernamelen;
	char			*groupname;
	size_t			groupnamelen;
	int				nb_files;		// Total number of files in current directory
	size_t			nlink_width;
	size_t			size_width;
	size_t			ownername_width;
	size_t			groupname_width;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_entry
{
	char			*fullpath;
	char			*name;
	int				length;
	time_t			timestamp;
	struct stat		stat;
	struct passwd	*passwd;
	struct group	*group;
	struct s_file	*next;
}					t_entry;

int					ft_ls(int ac, char **av);
void				parse_options(char *first_arg, int *options);
void				usage(char c);


void				ft_list_dir(DIR *dp, t_dir *cd, char *entryname, t_list *sdl);
int					ft_inspect_entry(t_entry *entry, char *path);
char				ft_type(mode_t mode);
void				determine_max_width(t_dir *directory, t_entry *entry);
void				initialize_directory(t_dir *directory);
void				parse_entry(char *entryname, t_dir *cd_struct);
char				*ft_pathjoin(const char *parent, const char *child);

char				*get_permissions(mode_t mode, int ugo);
void				modecat(char *str, mode_t st_mode);



void	get_pwstruct(uid_t st_uid, struct passwd **passwd);
void	get_grstruct(gid_t st_gid, struct group **group);
/*
** OUTPUT
*/

void	display_default();
void	display_long(t_dir *cd, t_entry *entry);

void	display_mode(mode_t st_mode);
void	display_nlink(nlink_t st_nlink, int width);
void	display_ownername(char *pw_name, size_t width);
void	display_groupname(char *gr_name, size_t width);
void	display_size(off_t st_size, size_t width);
void	display_mtim(time_t tv_sec);
void	display_filename(char *filename);

#endif
