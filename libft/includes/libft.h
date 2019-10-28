/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:05:58 by amalsago          #+#    #+#             */
/*   Updated: 2019/10/28 11:38:26 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define ABS(N) ((N) < (0) ? (-N) : (N))
# define MIN(A,B) ((A) < (B) ? (A) : (B))
# define MAX(A,B) ((A) > (B) ? (A) : (B))
# define BASE_LOWER "0123456789abcdefghijklmnopqrstuvwxyz"
# define BASE_UPPER "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** CONVERSIONS
*/

int					ft_atoi(const char *str);
char				*ft_ftoa_static(double number, unsigned int precision);
char				*ft_itoa(int n);
char				*ft_itoa_static(int number);
char				*ft_litoa(intmax_t number);
char				*ft_litoa_static(intmax_t n);
char				*ft_sitoa_base(intmax_t number, int base, int uppercase);
char				*ft_sitoa_base_static(intmax_t number, int base,
					int uppercase);
char				*ft_uitoa_base(uintmax_t number, int base, int uppercase);
char				*ft_uitoa_base_static(uintmax_t number, int base,
					int uppercase);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
** COUNTERS
*/

int					ft_count_words(char const *s, char c);
size_t				ft_silen(intmax_t number, int base);
size_t				ft_uilen(uintmax_t number, int base);

/*
** ERRORS
*/

void				ft_perror(const char *s);
void				ft_perror_exit(const char *s);

/*
** LISTS
*/

void				ft_lstadd_top(t_list **alst, t_list *new);
void				ft_lstadd_end(t_list **alst, t_list *new);
int					ft_lstbsort(t_list *head);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstprint(t_list *list);
void				ft_lstreverse(t_list **list);
t_list				*ft_lstreverse_recursive(t_list *list);

/*
** MEMORY
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *d, const void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_swap(void *a, void *b, size_t size);

/*
** PREDICATES
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isseparator(char c, char separator);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_iswhitespace(int c);

/*
** PRINT
*/

void				ft_putchar(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);

/*
** SORTING
*/

void				ft_qsort(char **array, int left, int right);

/*
** STRING
*/

char				*ft_realpath(const char *dirname, char const *basename);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
int					ft_strchr_index(char *s, char c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
size_t				ft_strcspn(const char *s, const char *charset);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s1);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strnew2d(size_t size);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strspn(const char *s, const char *charset);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char                *ft_strtok(char *str, const char *sep);
char				*ft_strtrim(char const *s);

#endif
