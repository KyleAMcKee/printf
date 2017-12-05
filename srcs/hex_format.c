/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:24:23 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 19:34:23 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_recursion(uintmax_t val, t_type type)
{
	char		hex[33];
	static int	i;

	i = 0;
	ft_strcpy(hex, HEX);
	if (val == 0)
		return (1);
	if (val > 0 && type.type == 'x')
	{
		hex_recursion(val / 16, type);
		ft_putchar(hex[val % 16]);
		i++;
	}
	else if (val > 0 && type.type == 'X')
	{
		hex_recursion(val / 16, type);
		ft_putchar(hex[val % 16 + 16]);
		i++;
	}
	return (i);
}

int	display_x(t_type type)
{
	int i;

	i = 0;
	if (type.flags.hash == 1 && type.res.unum > 0)
	{
		if (type.type == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		i += 2;
	}
	return (i);
}

t_type	set_hex_flags(t_type type, int len)
{
	if (type.flags.left == 1)
		type.flags.right = 0;
	if (type.flags.zero == 1)
		type.flags.right = 0;
	if (type.w_precision > type.width)
	{
		type.flags.right = 0;
		type.width = 0;
	}
	if (type.flags.hash == 1 && type.res.unum > 0)
		type.width -= 2;
	if (len > type.w_precision)
		type.width -= len;
	else
		type.width -= type.w_precision;
	if (type.w_precision > len)
		type.w_precision -= len;
	else
		type.w_precision = 0;
	return (type);
}

int	hex_length(uintmax_t val)
{
	int i;

	i = 0;
	while (val)
	{
		val /= 16;
		i++;
	}
	return (i);
}

int	hex_format(t_type type, va_list ap)
{
	int	digits;
	int	total;
	int	ret;

	total = 0;
	type = u_arg_conversion(type, ap);
	digits = hex_length(type.res.unum);
	type = set_hex_flags(type, digits);
	total += prepend_space(type);
	total += display_x(type);
	total += prepend_zero(type);
	if (type.flags.precision == 1 && type.w_precision == 0 && type.res.unum == 0)
		return (total);
	ret = hex_recursion(type.res.unum, type);
	if (ret == 1 && type.res.unum == 0)
		ft_putchar('0');
	total += ret;
	if (type.flags.left == 1)
		total += justify(type);
	return (total);
}
