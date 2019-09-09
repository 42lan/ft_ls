# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/03 12:02:20 by amalsago          #+#    #+#              #
#    Updated: 2019/09/09 13:20:35 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General

NAME		= ft_ls
LIBFTLS		= ft_ls.a
LIBNAME		= libft.a

# **************************************************************************** #
# GNU Compiler Collection

GCC			= /usr/bin/clang
WOPT		= -Wall -Wextra -Werror -g -g3 #-Weverythin
OOPT		= #-O2
IOPT		= -I $(INCDIR)

# **************************************************************************** #
# System commands

AR			= /usr/bin/ar -rc
MAKE		= /usr/bin/make -C
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p
RM			= /bin/rm -rf

# **************************************************************************** #
# Directories of source and object files

LIBDIR		= ./libft
SRCDIR		= ./sources
OBJDIR		= ./objects
INCDIR		= ./includes

# **************************************************************************** #
# List of source files

SRCNAME		= main.c	\
			  browse_dir.c\
			  browse_file.c\
			  ft_ls.c\
			  gets/get_argument_files.c\
			  gets/get_grstruct.c\
			  gets/get_link.c\
			  gets/get_major_minor.c\
			  gets/get_mode.c\
			  gets/get_options.c\
			  gets/get_permissions.c\
			  gets/get_pwstruct.c\
			  gets/get_stat.c\
			  gets/get_type.c\
			  output/display.c\
			  output/print_default.c\
			  output/print_filename.c\
			  output/print_groupname.c\
			  output/print_long.c\
			  output/print_major_minor.c\
			  output/print_mode.c\
			  output/print_mtime.c\
			  output/print_nlink.c\
			  output/print_options.c\
			  output/print_ownername.c\
			  output/print_size.c\
			  output/print_totalblocks.c\
			  output/print_usage.c\
			  predicates/is_hidden.c\
			  predicates/is_option.c\
			  tools/check_accessibility.c\
			  tools/cmp.c\
			  tools/fill_struct.c\
			  tools/form_relpath.c\
			  tools/ft_mergesort.c\
			  tools/lineup_files.c\
			  tools/new_directory.c\
			  tools/new_file.c\
			  tools/parse_argp.c\
			  tools/remove_file.c\
			  tools/reverse_files.c\
			  tools/set_extended_attribute.c\
			  tools/set_special_permissions.c\
			  wmax/determine_groupname_wmax.c\
			  wmax/determine_major_minor.c\
			  wmax/determine_namlen_wmax.c\
			  wmax/determine_nlink_wmax.c\
			  wmax/determine_ownername_wmax.c\
			  wmax/determine_size_wmax.c\
			  wmax/determine_wmax.c


# **************************************************************************** #
# Automatic variables where are listed the names of sources and objects files

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))
LFT			= $(addprefix $(LIBDIR)/, $(LIBNAME))
LFTLS		= $(addprefix $(PWD)/, $(LIBFTLS))
LFTOBJ		= $(LIBDIR)/objects/*/*.o

# **************************************************************************** #
# Extra

CR			= "\r"$(CLEAR)
CLEAR       = "\\033[0K"
EOC			= "\033[0;0m"
RED			= "\033[0;31m"
GREEN		= "\033[0;32m"
BASENAME	= `basename $(PWD)`

# **************************************************************************** #
# Rules

all: $(NAME) $(LFT)

$(NAME): $(LFT) $(OBJ)
	@$(AR) $(LIBFTLS) $(OBJ) $(LFTOBJ)
	@$(RANLIB) $(LIBFTLS)
	@$(GCC) $(LFTLS) $(LFT) -o $(NAME)
	@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(GCC) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@
	@printf $(CR)"[ ./$(BASENAME)/%s ]"$(CLEAR) $@

$(LFT):
	@$(MAKE) $(LIBDIR)

clean:
	@$(RM) $(OBJ) $(OBJDIR)

fclean: clean
	@$(RM)
	@$(RM) $(NAME) $(LIBFTLS)
	@printf $(CR)$(RED)"✗ ./tags, ./$(NAME) and ./$(LIBFTLS) are deleted\n"$(EOC)
	@$(MAKE) $(LIBDIR) fclean

re: fclean all

norm:
	$(NORMINETTE) $(SRCDIR) $(INCDIR) $(LIBDIR)/sources

.PHONY: all clean fclean re norm
