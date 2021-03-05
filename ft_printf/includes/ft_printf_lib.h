/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:07:12 by dlanzilo          #+#    #+#             */
/*   Updated: 2021/02/15 15:58:24 by dlanzilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LIB_H
# define FT_PRINTF_LIB_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <float.h>
# include <stdio.h>

# define H				1
# define HH				2
# define L				3
# define LL				4
# define J				5
# define Z				6
# define BIGL			7
# define POSITIVE		66
# define NEGATIVE		88
# define ALLSYMBOLS		"cspdiouxXfyb%#-+ .*0123456789hLljz"
# define CFLAGS			"#-+ .*0123456789hljz"
# define CONVERSION		"cspdiouxXf%"

typedef	struct	s_option
{
	char				*format;
	int					nprinted;
	int					i;
	int					len;
	int					minus;
	int					plus;
	int					space;
	int					zero;
	int					hash;
	int					width;
	int					precisiontf;
	int					precision;
	int					length;
	int					sign;
	int					zero_int;
}				t_option;

void			setzero(t_option *option);
int				ft_printf(const char *format, ...);
void			analyze_char(char *format, va_list args, t_option *options);
void			setzero_all(t_option *option);
int				ft_strlen(const char *str);
void			analyze_coversions(char *format, va_list args,
		t_option *options);
void			set_flags(char *format, t_option *options);
char			*ft_strchr(const char *s, int c);
int				ft_atoi(const char *str);
void			set_width(char *format, va_list args, t_option *options);
void			set_precision(char *format, va_list args, t_option *options);
void			set_conversion(char *format, t_option *options, va_list args);
void			ft_string(t_option *options, va_list args);
void			left_padding(char *str, t_option *options, int c);
void			ft_putstr(char *str);
void			right_padding(char *str, t_option *options, int c);
void			ft_int(t_option *options, va_list args);
void			left_padding_int(char *str, t_option *options, int c);
char			*ft_itoa(int nb);
void			right_padding_int(char *str, t_option *options, int c);
char			*ft_hex(char *format, t_option *options, unsigned int n);
void			ft_strreverse(char *s);
void			ft_hexadecimal(char *format, t_option *options, va_list args);
int				ifhex(t_option *option, unsigned int n);
void			if_percent(t_option *options);
void			left_padding_percent(int c, t_option *options);
void			right_padding_percent(int c, t_option *options);
void			ft_char(t_option *options, va_list args);
void			left_padding_char(int c, t_option *options, int y);
void			right_padding_char(int c, t_option *options, int y);
char			*apply_precision_string(char *str, t_option *options);
char			*apply_int_precision(t_option *options, char *str);
void			ft_pointers(t_option *option, va_list args);
void			ft_bzero(void *s, size_t len);
char			*ft_itoa_base(uintmax_t value, uintmax_t base);
int				unsigned_nbr_len(uintmax_t n, int base);
char			findchar(t_option *option);
void			ifudecint(t_option *f, va_list ap);
char			*conv_p(t_option *options, va_list ap);
void			exit_error(char *er_mess, int nbfree, ...);
char			*ft_strnew(size_t size);
char			*ft_strncat(char *s1, char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
void			lengths(int n, size_t *len, int *weight);
int				ft_isdigit(int c);

#endif
