# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 11:06:32 by amalsago          #+#    #+#              #
#    Updated: 2019/09/02 13:00:49 by amalsago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# General

NAME		= libft.a

# **************************************************************************** #
# GNU Compiler Collection

GCC			= /usr/bin/clang
WOPT		= -Wall -Wextra -Werror
OOPT		= -O2
IOPT		= -I $(INCDIR)

# **************************************************************************** #
# System commands

AR			= /usr/bin/ar -rc
RM			= /bin/rm -rf
RANLIB		= /usr/bin/ranlib
NORMINETTE	= /usr/bin/norminette
MKDIR		= /bin/mkdir -p

# **************************************************************************** #
# Directories of source and object files

INCDIR		= ./includes
SRCDIR		= ./sources
OBJDIR		= ./objects

# **************************************************************************** #
# List of source and header files

SRCNAME		= conversions/ft_atoi.c					\
			  conversions/ft_ftoa_static.c			\
			  conversions/ft_itoa.c					\
			  conversions/ft_itoa_static.c			\
			  conversions/ft_litoa.c				\
			  conversions/ft_litoa_static.c			\
			  conversions/ft_sitoa_base.c			\
			  conversions/ft_sitoa_base_static.c	\
			  conversions/ft_tolower.c				\
			  conversions/ft_toupper.c				\
			  conversions/ft_uitoa_base.c			\
			  conversions/ft_uitoa_base_static.c	\
			  counters/ft_cntwords.c	\
			  counters/ft_silen.c		\
			  counters/ft_uilen.c		\
			  errors/ft_error_exit.c	\
			  errors/ft_strerror.c		\
			  lists/ft_lstadd_top.c	\
			  lists/ft_lstadd_end.c	\
			  lists/ft_lstbsort.c	\
			  lists/ft_lstdel.c		\
			  lists/ft_lstdelone.c	\
			  lists/ft_lstiter.c	\
			  lists/ft_lstmap.c		\
			  lists/ft_lstnew.c		\
			  lists/ft_lstprint.c	\
			  lists/ft_lstreverse.c	\
			  lists/ft_lstreverse_recursive.c	\
			  memory/ft_bzero.c		\
			  memory/ft_memalloc.c	\
			  memory/ft_memccpy.c	\
			  memory/ft_memchr.c	\
			  memory/ft_memcmp.c	\
			  memory/ft_memcpy.c	\
			  memory/ft_memdel.c	\
			  memory/ft_memmove.c	\
			  memory/ft_memset.c	\
			  memory/ft_swap.c		\
			  predicates/ft_isalnum.c		\
			  predicates/ft_isalpha.c		\
			  predicates/ft_isascii.c		\
			  predicates/ft_isdigit.c		\
			  predicates/ft_islower.c		\
			  predicates/ft_isprint.c		\
			  predicates/ft_isseparator.c	\
			  predicates/ft_isspace.c		\
			  predicates/ft_isupper.c		\
			  predicates/ft_iswhitespace.c	\
			  print/ft_putchar.c	\
			  print/ft_putchar_fd.c	\
			  print/ft_putendl.c	\
			  print/ft_putendl_fd.c	\
			  print/ft_putnbr.c		\
			  print/ft_putnbr_fd.c	\
			  print/ft_putstr.c		\
			  print/ft_putstr_fd.c	\
			  sorting/ft_qsort.c	\
			  string/ft_strcat.c		\
			  string/ft_strchr.c		\
			  string/ft_strchr_index.c	\
			  string/ft_strclr.c		\
			  string/ft_strcmp.c		\
			  string/ft_strcpy.c		\
			  string/ft_strdel.c		\
			  string/ft_strdup.c		\
			  string/ft_strequ.c		\
			  string/ft_striter.c		\
			  string/ft_striteri.c		\
			  string/ft_strjoin.c		\
			  string/ft_strlcat.c		\
			  string/ft_strlen.c		\
			  string/ft_strmap.c		\
			  string/ft_strmapi.c		\
			  string/ft_strncat.c		\
			  string/ft_strncmp.c		\
			  string/ft_strncpy.c		\
			  string/ft_strnequ.c		\
			  string/ft_strnew.c		\
			  string/ft_strnew2d.c		\
			  string/ft_strnstr.c		\
			  string/ft_strrchr.c		\
			  string/ft_strsplit.c		\
			  string/ft_strstr.c		\
			  string/ft_strsub.c		\
			  string/ft_strtrim.c		\
			  utilities/ft_printf/ft_printf.c				\
			  utilities/ft_printf/parsing.c					\
			  utilities/ft_printf/specs/apply_specs.c		\
			  utilities/ft_printf/specs/set_flags.c			\
			  utilities/ft_printf/specs/set_length.c		\
			  utilities/ft_printf/specs/set_specs.c			\
			  utilities/ft_printf/specs/wildcard.c			\
			  utilities/ft_printf/tools/get_f.c				\
			  utilities/ft_printf/tools/buffer.c			\
			  utilities/ft_printf/tools/get_si.c			\
			  utilities/ft_printf/tools/get_ui.c			\
			  utilities/ft_printf/tools/initialization.c	\
			  utilities/ft_printf/types/type_b.c			\
			  utilities/ft_printf/types/type_c.c			\
			  utilities/ft_printf/types/type_d.c			\
			  utilities/ft_printf/types/type_f.c			\
			  utilities/ft_printf/types/type_o.c			\
			  utilities/ft_printf/types/type_p.c			\
			  utilities/ft_printf/types/type_s.c			\
			  utilities/ft_printf/types/type_u.c			\
			  utilities/ft_printf/types/type_x.c			\
			  utilities/ft_printf/types/percent.c			\
			  utilities/ft_printf/types/unknown.c			\
			  utilities/get_next_line/get_next_line.c

# **************************************************************************** #
# Automatic variables where are listed the names of source and object files

SRC			= $(addprefix $(SRCDIR)/, $(SRCNAME))
OBJ			= $(addprefix $(OBJDIR)/, $(SRCNAME:.c=.o))

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

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(RANLIB) $(NAME)
	@printf $(CR)$(GREEN)"✓ $(NAME) is created\n"$(EOC)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(dir $@)
	@$(GCC) $(WOPT) $(OOPT) $(IOPT) -c $< -o $@
	@printf $(CR)"[ ./libft/%s ]" $@

clean:
	@$(RM) $(OBJDIR)
	@printf $(CR)$(RED)"✗ ./libft/objects and its content are deleted\n"$(EOC)

fclean: clean
	@$(RM) $(NAME)
	@printf $(CR)$(RED)"✗ ./libft/$(NAME) is deleted\n"$(EOC)

re: fclean all

norm:
	$(NORMINETTE) $(INCDIR) $(SRC)

.PHONY: all clean fclean re norm
