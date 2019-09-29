/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:53:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/09/29 08:30:37 by amalsago         ###   ########.fr       */
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

# define FT_RPERM(m, i)		(m & (S_IRUSR >> i))
# define FT_WPERM(m, i)		(m & (S_IWUSR >> i))
# define FT_XPERM(m, i)		(m & (S_IXUSR >> i))
# define FT_XUGO(m)			(FT_XPERM(m, 0) || FT_XPERM(m, 3) || FT_XPERM(m, 6))

enum				e_options
{
	ALMOST_ALL,
	INDICATORS,
	RECURSIVE,
	SHOW_HIDDEN,
	UNSORTED,
	LONG_WITHOUT_OWNER,
	LONG_FORMAT,
	LONG_NUMERIC_ID,
	LONG_WITHOUT_GROUP,
	INDICATOR_SLASH,
	REVERSE_ORDER,
	MTIME_SORT,
	ONE_PER_LINE
};

typedef struct		s_wmax
{
	size_t			filename;
	size_t			ownername;
	size_t			groupname;
	size_t			size;
	size_t			major;
	size_t			minor;
	size_t			nlink;
}					t_wmax;

typedef struct		s_dir
{
	char			*name;
	char			*ownername;
	char			*groupname;
	size_t			total_blocks;
	size_t			nb_files;
	struct s_wmax	*wmax;
	struct s_file	*subdir_head;
	struct s_file	*file_head;
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
	size_t			major;
	size_t			minor;
	struct s_file	*next;
}					t_file;

typedef struct		s_argp
{
	char			sign;
	unsigned		active : 1;
	char			*description;
}					t_argp;

void				browse_directory(const char *path);
void				browse_file(const char *filename);
int					ft_ls(t_file *head);
void				fill_struct(t_file *file);
t_file				*new_file(const char *path, const char *name);
t_dir				*new_directory(const char *path);
void				display(t_dir *directory);
void				print_default(t_dir *directory);
void				print_fts_open(void);
void				print_help(void);
void				print_error(const char *filename, int errnum);
void				print_long(t_dir *directory);
void				print_one_per_line(t_dir *directory);
void				print_filename(t_file *file, int width);
void				print_groupname(const char *groupname, size_t width);
void				print_major_minor(t_wmax *wmax, size_t major, size_t minor);
void				print_mode(const char *mode);
void				print_mtime(time_t tv_sec);
void				print_nlink(nlink_t st_nlink, int width);
void				print_options(t_argp g_argp[]);
void				print_ownername(const char *ownername, size_t width);
void				print_size(off_t st_size, size_t width);
void				print_totalblocks(size_t total_blocks);
void				print_usage(char c);
int					is_dotdot(const char *name);
int					is_hidden(const char *name);
int					need_to_skip(const char *name);
int					is_option(const char *argv);
void				check_accessibility(t_file **head);
char				*form_relpath(const char *dirname, const char *basename);
void				ft_mergesort(t_file **headref,
					int (*cmp)(t_file *, t_file *));
void				lineup_files(t_file **head);
int					mtime_cmp(t_file *file_a, t_file *file_b);
int					name_cmp(t_file *file_a, t_file *file_b);
void				parse_argp(const char *argv);
void				remove_file(t_file *file);
void				reverse_files(t_file **head);
void				set_extended_attribute(t_file *file);
void				set_special_permissions(mode_t st_mode, char **str);
void				append_indicator(t_file *file);
void				determine_groupname_wmax(t_wmax *wmax, t_file *file);
void				determine_filename_wmax(t_wmax *wmax, t_file *file);
void				determine_nlink_wmax(t_wmax *wmax, t_file *file);
void				determine_major_minor_wmax(t_wmax *wmax, t_file *file);
void				determine_ownername_wmax(t_wmax *wmax, t_file *file);
void				determine_size_wmax(t_wmax *wmax, t_file *file);
void				determine_wmax(t_wmax *wmax, t_file *file);
t_file				*get_argument_files(int argc, char **argv);
void				get_options(int argc, char **argv);
char				get_type(mode_t mode);
void				get_link(t_file *file);
void				get_major_minor(t_file *file);
void				get_mode(t_file *file);
int					get_stat(t_file *file);
struct passwd		*get_pwstruct(uid_t st_uid);
struct group		*get_grstruct(gid_t st_gid);
char				*get_permissions(mode_t mode, int ugo);
void				apply_options(t_dir *directory);
void				append_file(t_dir **directory, t_file *file);

#endif
