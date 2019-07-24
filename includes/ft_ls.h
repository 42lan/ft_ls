/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:53:19 by amalsago          #+#    #+#             */
/*   Updated: 2019/07/24 19:08:59 by amalsago         ###   ########.fr       */
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
	char			*name;				// Current directory name
	size_t			length;				// Length of current directory
	char			*parent_name;		// Parent name of current directory
	char			*fullpath;
	char			*ownername;
	char			*groupname;
	struct s_file	*file_head;			// pointer to the first node in list of files
	t_list			*sdir_head;			// pointer to the first node in list of subdirs
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
	struct stat		*stat;
	char			*ownername;
	char			*groupname;
	struct s_file	*next;
}					t_file;

int		ft_ls(int ac, char **av);
t_dir	*browse_dir(const char *path);
void	recursive_browse(t_list *sdir_head);
void	max_namlen_width(t_dir *directory, t_file *entry);
void	determine_wmax(struct dirent *dirent, t_file *file, t_dir *current_dir);
void	determine_namlen_wmax(struct dirent *dirent, t_dir *current_dir);
void	determine_nlink_wmax(t_file *file, t_dir *current_dir);
void	determine_size_wmax(t_file *file, t_dir *current_dir);

void	list_dir(DIR *dp, t_dir *current_dir, char *entryname, t_list *subdir_list, int *options);

int		inspect_file(t_file *entry, char *path);
t_dir	*initialize_directory(void);

void	fill_file_struct(t_file *file, struct dirent *dirent);
int		check_subdir(t_file *file, struct dirent *dirent, t_dir *current_dir);

/* PREDICATES */
int		is_hidden(const char *name);
int		is_directory(mode_t st_mode);

/* PARSING */
int		parse_options(int ac, char **av, int *opt_bits);
void	parse_entry(char *entryname, t_dir *current_dir);

/* GETS */
struct stat		*get_stat(const char *path);
char			get_type(mode_t mode);
struct passwd	*get_pwstruct(uid_t st_uid);
struct group	*get_grstruct(gid_t st_gid);
char			*get_permissions(mode_t mode, int ugo);

/* OUTPUT */
void	display_usage(char c);
void	display_default(t_dir *current_dir);
void	display_long(t_dir *current_dir);
void	display_total(size_t total_blocks);
void	display_mode(mode_t st_mode);
void	display_nlink(nlink_t st_nlink, int width);
void	display_ownername(char *ownername, size_t width);
void	display_groupname(char *groupname, size_t width);
void	display_size(off_t st_size, size_t width);
void	display_mtim(time_t tv_sec);
void	display_filename(char *filename, size_t width);

/* TOOLS */
void	modecat(char *str, mode_t st_mode);
char	*form_path(const char *dirname, const char *basename);

/* LINKED LIST */
t_file	*new_file(void);
t_file	*push_end(t_file *head, t_file *file);
#endif
