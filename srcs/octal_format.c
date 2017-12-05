/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:30:27 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 18:59:45 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type		set_flags_octal(t_type type, int len)
{
	type.width -= len;
	if (type.flags.left == 1)
		type.flags.right = 0;
	if (type.flags.zero == 1)
		type.flags.right = 0;
	if (type.w_precision > type.width)
		type.width = 0;
	if (type.flags.hash == 1)
		type.width--;
	if (type.w_precision > len)
		type.w_precision -= len;
	else
		type.w_precision = 0;
	type.width -= type.w_precision;
	return (type);
}

int			display_zero(t_type type)
{
	int i;

	i = 0;
	if (type.flags.hash == 1 &&
		(type.res.unum != 0 || type.flags.precision == 1))
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

int			octal_recursion(uintmax_t val)
{
	char		oct[9];
	static int	i;

	i = 0;
	ft_strcpy(oct, OCT);
	if (val == 0)
		return (1);
	if (val > 0)
	{
		octal_recursion(val / 8);
		ft_putchar(oct[val % 8]);
		i++;
	}
	return (i);
}

int			octal_length(uintmax_t val)
{
	int i;

	i = 0;
	while (val)
	{
		val /= 10;
		i++;
	}
	return (i);
}

int			octal_format(t_type type, va_list ap)
{
	int digits;
	int i;

	type = u_arg_conversion(type, ap);
	digits = octal_length(type.res.unum);
	i = 0;
	type = set_flags_octal(type, digits);
	i += prepend_space(type);
	i += prepend_zero(type);
	i += display_zero(type);
	if (type.flags.precision == 1 &&
		type.w_precision == 0 && type.res.unum == 0)
		return (i);
	i += octal_recursion(type.res.unum);
	if (type.res.unum == 0)
		ft_putchar('0');
	if (type.flags.left == 1)
		i += justify(type);
	return (i);
}
