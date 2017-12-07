/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:45:05 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/07 11:14:46 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include "color.h"
/*REMOVE*/ #include <stdio.h> /*REMOVE*/

# define TYPES "sSpdDioOuUxXcC%bB"
# define HEX "0123456789abcdef0123456789ABCDEF"
# define OCT "01234567"
# define DEC "0123456789"
# define LENGTH "hhllzj"

typedef struct		s_flags
{
	int		hash;
	int		zero;
	int		left;
	int		right;
	int		plus;
	int		space;
	int		precision;
	int		percent;
	int		asterisk;
}
					t_flags;

typedef	struct		s_pos
{
	int		i;
	int		start;
}
					t_pos;

typedef struct		s_length
{
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		j;
	int		z;
}					t_length;

typedef union
{
	wchar_t			chr;
	char			*str;
	wchar_t			*wstr;
	intmax_t		num;
	uintmax_t		unum;
}					t_arg_res;

typedef struct		s_type
{
	t_flags			flags;
	t_length		length;
	t_arg_res		res;
	int				width;
	int				w_precision;
	int				ret;
	char			type;
}					t_type;

t_type	check_flags(const char *str, t_type type, int *i, va_list ap);
t_type	check_length(const char *str, t_type type, int *i);
t_type	u_arg_conversion(t_type type, va_list ap);
t_type	arg_conversion(t_type type, va_list ap);
t_type	char_conversion(t_type type, va_list ap);
t_type	check_width(const char *str, t_type type, int *i);
t_type	check_asterisk(t_type type, va_list ap);
int		check_conv(char c, t_type type);
int		is_flag(char c);
int		ft_printf(const char *restrict format, ...);
int		type_handler(t_type type, va_list list);
int		char_format(t_type type, va_list ap);
int		string_format(t_type type, va_list ap);
int		int_format(t_type type, va_list ap);
int		binary_format(t_type type, va_list ap);
int		hex_format(t_type type, va_list ap);
int		octal_format(t_type type, va_list ap);
int		unsigned_format(t_type type, va_list ap);
int		percent_format(t_type type);
int		pointer_format(t_type type, va_list ap);
int		wchar_format(t_type type, va_list ap);
int		wchar_string_format(t_type type, va_list ap);
int		width_format(t_type type, int amount);
int		width_format_after(t_type type, int amount);
int		undef_format(t_type type);
int		display_sign(t_type type);
int		justify(t_type type);
int		prepend_zero(t_type type);
int		prepend_space(t_type type);
int		is_len(char c);
void	print_max(intmax_t num);
void	print_status(t_type type);

#endif
