/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:53:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/09 13:19:54 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
# include <dirent.h>
# include <grp.h>
# include <pwd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
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
	char			*name;
	size_t			length;
	char			*ownername;
	char			*groupname;
	struct s_file	*file_head;
	struct s_file	*subdir_head;
	size_t			total_blocks;
	size_t			namlen_wmax;
	size_t			nlink_wmax;
	size_t			size_wmax;
	size_t			ownername_wmax;
	size_t			groupname_wmax;
	ssize_t			major_wmax;
	ssize_t			minor_wmax;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_file
{
	char			*name;
	size_t			namlen;
	char			*relpath;
	char			target[PATH_MAX];
	size_t			targetlen;
	char			*mode;
	struct stat		*stat;
	char			*ownername;
	char			*groupname;
	ssize_t			major;
	ssize_t			minor;
	struct s_file	*next;
}					t_file;

typedef struct		s_argp
{
	char			sign;
	unsigned		active : 1;
	char			*description;
}					t_argp;

void				browse_dir(const char *path);
void				browse_file(const char *path, t_file *file);
int					ft_ls(t_file *head);

void				fill_struct(t_file *file);
t_file				*new_file(const char *path, const char *name);
t_dir				*new_directory(const char *path);

void				display(t_dir *current_dir);
void				print_default(t_dir *current_dir);
void				print_long(t_dir *current_dir);
void				print_filename(t_file *file);
void				print_groupname(const char *groupname, size_t width);
void				print_major_minor(t_dir *dir, size_t major, ssize_t minor);
void				print_mode(const char *mode);
void				print_mtime(time_t tv_sec);
void				print_nlink(nlink_t st_nlink, int width);
void				print_options(t_argp g_argp[]);
void				print_ownername(const char *ownername, size_t width);
void				print_size(off_t st_size, size_t width);
void				print_totalblocks(size_t total_blocks);
void				print_usage(char c);

int					is_hidden(const char *name);
int					is_option(const char *av);

void				check_accessibility(t_file **head);
char				*form_relpath(const char *dirname, const char *basename);
void				ft_mergesort(t_file **headref,
					int (*cmp)(t_file *, t_file *));
void				lineup_files(t_file **head);
int					mtime_cmp(t_file *file_a, t_file *file_b);
int					name_cmp(t_file *file_a, t_file *file_b);
void				parse_argp(const char *av);
void				remove_file(t_file *file);
void				reverse_files(t_file **head);
void				set_extended_attribute(t_file *file);
void				set_special_permissions(mode_t st_mode, char **str);

void				determine_groupname_wmax(t_dir *directory, t_file *file);
void				determine_namlen_wmax(t_dir *directory, t_file *file);
void				determine_nlink_wmax(t_dir *directory, t_file *file);
void				determine_major_minor_wmax(t_dir *directory, t_file *file);
void				determine_ownername_wmax(t_dir *directory, t_file *file);
void				determine_size_wmax(t_dir *directory, t_file *file);
void				determine_wmax(t_dir *directory, t_file *file);

t_file				*get_argument_files(int ac, char **av);
void				get_options(int ac, char **av);
char				get_type(mode_t mode);
void				get_link(t_file *file);
void				get_major_minor(t_file *file);
void				get_mode(t_file *file);
int					get_stat(const char *path, t_file *file);
struct passwd		*get_pwstruct(uid_t st_uid);
struct group		*get_grstruct(gid_t st_gid);
char				*get_permissions(mode_t mode, int ugo);

#endif
