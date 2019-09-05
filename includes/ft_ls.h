/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:53:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/05 18:42:29 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define place_cursor(x,y) ft_printf("\033[%d;%dH", (y), (x))
#include <errno.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h> // To get terminal size
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <time.h>
# include <unistd.h>
# include <uuid/uuid.h>
# include "../libft/includes/libft.h"
# include "colors.h"

# define LONG_FORMAT	0
# define RECURSIVE		1
# define SHOW_HIDDEN	2
# define REVERSE_ORDER	3
# define MTIME_SORT		4
# define ONE_PER_LINE	5

typedef struct		s_dir
{
	char			*name;				// Current directory name
	size_t			length;				// Length of current directory
	char			*ownername;
	char			*groupname;
	struct s_file	*file_head;			// pointer to the first node in list of files
	struct s_file	*subdir_head;			// pointer to the first node in list of subdirs
	size_t			nb_files;			// Total number of files in current directory
	size_t			total_blocks;		// the total number of blocks used by the files in the directory
	size_t			namlen_wmax;		// Maximum length of a filename in directory
	size_t			nlink_wmax;
	size_t			size_wmax;
	size_t			ownername_wmax;
	size_t			groupname_wmax;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_file
{
	char			*name;
	size_t			namlen;
	char			*relpath;
	struct stat		*stat;
	char			*ownername;
	char			*groupname;
	struct s_file	*next;
}					t_file;

typedef struct		s_argp
{
	char			sign;
	unsigned		active : 1;
	char			*description;
}					t_argp;

t_dir				*browse_dir(const char *path);
void				browse_file(const char *path, t_file *file);
int					ft_ls(t_file *head);

void				fill_file_struct(t_file *file, struct dirent *dirent);
t_file				*new_file(const char *name, const char *path);
t_dir				*new_directory(const char *path);

/* PREDICATES */
int					is_hidden(const char *name);
int					is_option(const char *av);

/* OUTPUT */
void				display(t_dir *current_dir);
void				display_default(t_dir *current_dir);
void				display_filename(t_file *file);
void				display_groupname(const char *groupname, size_t width);
void				display_long(t_dir *current_dir);
void				display_mode(mode_t st_mode);
void				display_mtim(time_t tv_sec);
void				display_nlink(nlink_t st_nlink, int width);
void				display_options(t_argp g_argp[]);
void				display_ownername(const char *ownername, size_t width);
void				display_size(off_t st_size, size_t width);
void				display_total(size_t total_blocks);
void				display_usage(char c);

/* TOOLS */
void				check_accessibility(t_file **head);
char				*form_relpath(const char *dirname, const char *basename);
void				ft_mergesort(t_file **headref, int (*cmp)(t_file *, t_file *));
void				lineup_files(t_file **head);
int					mtime_cmp(t_file *file_a, t_file *file_b);
int					name_cmp(t_file *file_a, t_file *file_b);
void				parse_argp(const char *av);
void				remove_file(t_file *file);
void				reverse_files(t_file **head);
void				set_special_permissions(mode_t st_mode, char **str);


/* WMAX */
void				determine_groupname_wmax(t_file *file, t_dir *current_dir);
void				determine_namlen_wmax(struct dirent *dirent, t_dir *current_dir);
void				determine_nlink_wmax(t_file *file, t_dir *current_dir);
void				determine_ownername_wmax(t_file *file, t_dir *current_dir);
void				determine_size_wmax(t_file *file, t_dir *current_dir);
void				determine_wmax(struct dirent *dirent, t_file *file, t_dir *current_dir);

/* GETS */
t_file				*get_argument_files(int ac, char **av);
void				get_options(int ac, char **av);
char				get_type(mode_t mode);
char				*get_mode(mode_t st_mode);
int					get_stat(const char *path, t_file *file);
struct passwd		*get_pwstruct(uid_t st_uid);
struct group		*get_grstruct(gid_t st_gid);
char				*get_permissions(mode_t mode, int ugo);

#endif
