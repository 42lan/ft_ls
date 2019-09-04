/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:53:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/04 11:24:51 by amalsago         ###   ########.fr       */
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

void	lineup_files(t_file **head);
void	print_argument_files(t_file *head);
void	check_accessibility(t_file **head);
int		ft_ls(t_file *head);
t_dir	*browse_dir(const char *path);
void	browse_file(const char *path, t_file *file);
void	max_namlen_width(t_dir *directory, t_file *entry);
void	determine_wmax(struct dirent *dirent, t_file *file, t_dir *current_dir);
void	determine_namlen_wmax(struct dirent *dirent, t_dir *current_dir);
void	determine_nlink_wmax(t_file *file, t_dir *current_dir);
void	determine_size_wmax(t_file *file, t_dir *current_dir);
void	determine_ownername_wmax(t_file *file, t_dir *current_dir);
void	determine_groupname_wmax(t_file *file, t_dir *current_dir);

void	list_dir(DIR *dp, t_dir *current_dir, const char *entryname, t_list *subdir_list, int *options);

int		inspect_file(t_file *entry, const char *path);
t_dir	*new_directory(const char *path);

void	fill_file_struct(t_file *file, struct dirent *dirent);
int		check_subdir(t_file *file, t_dir *current_dir);

/* PREDICATES */
int		is_option(const char *av);
int		is_hidden(const char *name);
int		is_directory(mode_t st_mode);

/* PARSING */
void	parse_argp(const char *av);
int		parse_options(int ac, char **av, int *opt_bits);
void	parse_entry(const char *entryname, t_dir *current_dir);

/* GETS */
t_file			*get_argument_files(int ac, char **av);
void			get_options(int ac, char **av);
char			get_type(mode_t mode);
char			*get_mode(mode_t st_mode);
int				get_stat(const char *path, t_file *file);
struct passwd	*get_pwstruct(uid_t st_uid);
struct group	*get_grstruct(gid_t st_gid);
char			*get_permissions(mode_t mode, int ugo);

/* OUTPUT */
void	display_usage(char c);
void	display(t_dir *current_dir);
void	display_default(t_dir *current_dir);
void	display_long(t_dir *current_dir);
void	display_total(size_t total_blocks);
void	display_mode(mode_t st_mode);
void	display_nlink(nlink_t st_nlink, int width);
void	display_ownername(const char *ownername, size_t width);
void	display_groupname(const char *groupname, size_t width);
void	display_size(off_t st_size, size_t width);
void	display_mtim(time_t tv_sec);
void	display_filename(t_file *file);
void	print_options(t_argp g_argp[]);

/* TOOLS */
char	*form_relpath(const char *dirname, const char *basename);
int		mtime_cmp(t_file *file_a, t_file *file_b);
int		name_cmp(t_file *file_a, t_file *file_b);
void	remove_file(t_file *file);

/* LINKED LIST */
t_file	*new_file(const char *name, const char *path);

/* SORTING */
void	ft_mergesort(t_file **headref, int (*cmp)(t_file *, t_file *));

#endif
