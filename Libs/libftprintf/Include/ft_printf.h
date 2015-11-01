/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 13:46:00 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/02 16:55:04 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdint.h>
# include <stdarg.h>

# define OPT_CONV   "bsSpdDioOuUxXcC$"
# define OPT_FLAG   "#0-+ 123456789."
# define CONV       "$bsSpdDioOuUxXcC%"
# define OPT_CONV_N "$bspdiouxc%"
# define OPT_CONV_U "DOUSC"
# define BASE_16X   "0123456789abcdef"
# define BASE_16X_U "0123456789ABCDEF"
# define BASE_10    "0123456789"
# define BASE_8     "01234567"
# define BASE_2     "01"

# define FCT_PTR fcts[c]

typedef struct	s_opt
{
	int					opt_base;
	unsigned short		opt_sharp			: 1;
	unsigned short		opt_pos				: 1;
	unsigned short		opt_neg				: 1;
	unsigned short		opt_0				: 1;
	unsigned short		opt_space			: 1;
	unsigned short		opt_dot				: 1;
	unsigned short		opt_wchar			: 1;
	enum
	{
		opt_none,
		opt_l,
		opt_ll,
		opt_h,
		opt_hh,
		opt_j,
		opt_z
	}					opt_type;
	short				precision;
	short				lenght;
	short				error;
	unsigned short		process_invalide	: 1;
	char				type_conv;
	short				fd;
	va_list				*lst;
}				t_opt;

typedef struct	s_init
{
	short		return_error;
	char		*sf;
	va_list		ap;
	t_opt		opt;
	int			fd;
	size_t		strlen;
}				t_init;

typedef struct	s_var
{
	char	*ropt;
	char	*s1;
	char	*st;
	char	*sf;
	char	*str_opt;
	short	cmp;
	short	i;
	short	end;
	short	error;
	t_init	*init;
	t_opt	*opt;
}				t_var;

typedef struct	s_replace
{
	char	*s1;
	char	*s2;
	char	*mod;
	size_t	jump;
	size_t	ns1;
	size_t	ns2;
}				t_replace;

int				ft_printf(char *str, ...);
typedef char	*(*t_fcts_flag)(char *str, t_opt *opt);
typedef char	*(*t_fcts_conv)(va_list lst, t_opt *opt);
int				setup_fcts(t_fcts_flag *fct_flag, t_fcts_conv *fct_conv);
typedef	char	*(*t_fcts_spe)(uintmax_t a, char *b);
char			*ft_special(t_opt opt, va_list lst, char *str, t_fcts_spe spe);
char			*ft_format(char *str, t_opt opt, int mod);
char			*handle_fd(va_list ap, t_opt *opt);
char			*handle_hexa(va_list lst, t_opt opt, int mod);
char			*handle_lenght(char *str, t_opt *opt);
char			*handle_percent(va_list lst, t_opt *opt);
char			*handle_decimal(va_list lst, t_opt *opt);
char			*handle_uint(va_list lst, t_opt *opt);
char			*handle_binaire(va_list lst, t_opt *opt);
char			*handle_oct(va_list lst, t_opt *opt);
char			*handle_ptr(va_list lst, t_opt *opt);
char			*handle_str(va_list lst, t_opt *opt);
char			*handle_wstr(va_list lst, t_opt *opt);
char			*handle_char(va_list lst, t_opt *opt);
char			*handle_wchar(va_list lst, t_opt *opt);
char			*handle_l(char *str, t_opt *opt);
char			*handle_h(char *str, t_opt *opt);
char			*handle_j(char *str, t_opt *opt);
char			*handle_z(char *str, t_opt *opt);
char			*handle_sharp(char *str, t_opt *opt);
char			*handle_0(char *str, t_opt *opt);
char			*handle_space(char *str, t_opt *opt);
char			*handle_pos(char *str, t_opt *opt);
char			*handle_neg(char *str, t_opt *opt);
char			*handle_dot(char *str, t_opt *opt);
int				handle_star(t_opt *opt, int mod);
char			*ft_printf_replace(t_replace rep, t_var *v);
char			*add_precision(char *str, t_opt *opt, int mod);
char			*add_lenght(char *str, t_opt *opt, int mod);
char			*add_0(char *str, t_opt *opt, int mod);
char			*add_sharp(char *str, t_opt *opt, int mod);
char			*add_pos(char *str, t_opt *opt, int mod);
char			*add_space(char *str, t_opt *opt, int mod);
char			*hexa_purge(char *s1);
#endif
