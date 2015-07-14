/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:05:43 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/09 17:22:12 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <wchar.h>
# include <get_next_line.h>

# define MAGENTA		"\033[35m"
# define BMAGENTA		"\033[37m"
# define CYAN			"\033[1;36m"
# define BCYAN			"\033[46mCyan"
# define GREEN			"\033[1;32;40m"
# define BGREEN			"\033[1;32;43m"
# define YELLOW			"\033[1;33;40m"
# define BYELLOW		"\033[1;33;45m"
# define RED			"\033[1;31;40m"
# define BRED			"\033[1;31;43m"
# define BLUE			"\033[1;34;40m"
# define BBLUE			"\033[1;34;46m"
# define RESET			"\033[0m"

# define C_NONE         "\033[0m"
# define C_BOLD         "\033[1;1m"
# define C_BLACK        "\033[0;30;40m"
# define C_RED          "\033[0;31;40m"
# define C_GREEN        "\033[0;32;40m"
# define C_BROWN        "\033[0;33;40m"
# define C_BLUE         "\033[0;34;40m"
# define C_MAGENTA      "\033[0;35;40m"
# define C_CYAN         "\033[0;36;40m"
# define C_GRAY         "\033[0;37;40m"

# define TRUE			1
# define FALSE			0

# define TYPE_STR		0
# define TYPE_INT		1
# define TYPE_UINT		2
# define TYPE_ULONG		3
# define TYPE_CHAR		4

typedef unsigned int		t_uint;
typedef unsigned short		t_ushort;
typedef unsigned short		t_uchar;
typedef unsigned long int	t_ulong;
typedef int					t_bool;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_listdbl
{
	void				*content;
	size_t				content_size;
	struct s_listdbl	*next;
	struct s_listdbl	*prev;
}					t_listdbl;

typedef struct		s_listaz
{
	t_listdbl	**alist;
	t_listdbl	**zlist;
}					t_listaz;

int					ft_array_count(void **ptr);

int					ft_atoi(const char *c);
char				*ft_itoa(intmax_t i);
char				*ft_utoa(uintmax_t i);
char				*ft_wtoa(wint_t wi);
char				*ft_ntoa(uintmax_t ui, char *c);
int					ft_tolower(int c);
int					ft_toupper(int c);
long int			ft_strtol(char *line);
char				*ft_strcat(char *s1, const char *s2);

void				ft_bzero(void *s, size_t n);
char				*ft_realloc(char *str, size_t len);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_multi_memcpy(void *dst, int nbr_elem, ...);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *src, int c, size_t len);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

int					ft_findchr(const char *src, int c);
void				ft_strclr(char *s);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strisempty(char *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strchr(const char *src, int c);
char				*ft_nstrchr(const char *s, int c, size_t n);
char				*ft_nstrrchr(const char *s, int c, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strstrchr(const char *s1, const char *s2);
char				*ft_nstrstrchr(const char *s1, const char *s2, size_t n);
char				*ft_strchange(char *s1, char *mod, char *new);
char				*ft_strtrim(char const *s);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_multi_strjoin(size_t nbr_elem, ...);
char				*ft_strnjoin(char const *s1, char const *s2, size_t n);
char				*ft_strjoin_free(char *src, char *join, int mod);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_multi_strcmp(size_t nbr_elem, char *str, ...);
void				ft_strdel(char **as);
void				ft_strndel(int a, ...);
void				ft_tabndel(char	**tab, size_t n);
void				ft_tabdel(char **tab);
char				**ft_tabcpy_by_value(char **tab, size_t offset);
char				**ft_tabcpy_by_ptr(char **tab, size_t offset);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *str, size_t n);
char				*ft_strsub(char const *s1, unsigned int start, size_t len);
char				*ft_wstrsub(char const *s1, unsigned int s, size_t len);
char				**ft_strsplit(char const *s, char c);
char				**ft_ptrsplit(char *str, int c);
char				**ft_nstrsplit(char const *s, char c, int nbr_val);
char				*ft_strcpy(char *dst, char *src);
size_t				ft_strlen(const char *str);
size_t				ft_strlen_by_c(const char *str, int c);
size_t				ft_wstrlen(const wchar_t *str);
int					ft_wlen(wchar_t c);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				**ft_strsplit(char const *s, char c);
char				*ft_strset(char *s1, int pos, int nbr, int car);
char				*ft_insert(char *tab, int type, char *value);
char				**ft_insert_data_tab2d(char **tab, int row, int col, ...);
int					ft_count_carac(char *str, int car);

char				*ft_replace(char *s1, char *s2, char *s3);
char				*ft_nreplace(char *s1, char *s2, char *s3, size_t n);
char				*ft_n1replace(char *s1, char *mod, char *s2, size_t n);
char				*ft_replace_free(char *s1, char *s2, char *s3, int i);

int					ft_isspace(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_strisupper(char *str);
int					ft_strislower(char *str);
int					ft_nstrisupper(char *str, size_t n);
int					ft_nstrisnlower(char *str, size_t n);
int					ft_count_split(char *str, char c);
int					ft_strcount(char *str, int c);

void				ft_putchar(char c);
void				ft_putwchar(wchar_t c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_c(char const *str, char *color);
void				ft_putendl2_c(char const *s1, char const *s2, char *color);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_dl(int n);
void				ft_putstr(char const *s);
void				ft_putnbr_ull(unsigned long long int n);
void				ft_putnbr_ll(long long int a);

void				ft_nputstr(int n, ...);
int					ft_putnstr(char const *s, size_t n);
void				ft_putstr_c(char const *s, char *color);
void				ft_putstr_fd(char const *s, int fd);
int					ft_putnstr_fd(char const *s, size_t n, short fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *ne);
void				ft_lstadd_back(t_list **alst, t_list *ne);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
t_listdbl			*ft_lstdblnew(void const *content, size_t content_size);
typedef void		(*t_del)(void *a, size_t b);
void				ft_lstdbldel(t_listdbl **alst, t_del del);
void				ft_lstdbldelone(t_listdbl **alst, t_del del);
void				ft_putnbr_ull(unsigned long long int n);
void				ft_putnbr_ll(long long int n);
int					ft_ll_len(long long int n);
void				ft_putstr_n(char *s, int start, int len);
char				*ft_strjoin_c(char c);
char				*ft_strjoin_null(char const *s1, char const *s2);
int					ft_ull_len(unsigned long long int n);
char				*ft_ulltoa(unsigned long long int arg);
int					ft_wchar_len(wchar_t arg);
void				ft_putstr_col(char *s, char *color, int fd);
long long int		ft_atoll(char *str);
void				ft_error_gestion(char *s, int fd);

long				ft_pow(int valeur, int power);
int					ft_round(float f);
int					ft_ceil(float f);
#endif
