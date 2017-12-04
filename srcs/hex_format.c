/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:24:23 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/03 20:41:57 by kmckee           ###   ########.fr       */
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
	if (type.flags.hash == 1 && type.result.u_num_jug > 0)
	{
		if (type.type == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		i += 2;
	}
	return (i);
}

int	precision_check(t_type type)
{
	int i;

	i = 0;
	while (i < type.width)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int	hex_format(t_type type, va_list ap)
{
	uintmax_t	temp;
	int			digits;
	int			i;

	type = u_arg_conversion(type, ap);
	temp = type.result.u_num_jug;
	digits = 0;
	i = 0;
	if (type.flags.precision == 1 && type.result.u_num_jug == 0)
		return (precision_check(type));
	while (temp /= 10)
		digits++;
	digits = digits + (type.flags.hash * 2);
	if (type.flags.right == 1 && type.width > digits)
		i += width_format(type, type.width - digits - 1, digits);
	i += display_x(type);
	if (type.result.u_num_jug == 0)
		ft_putchar('0');
	if (type.width > digits && type.flags.zero == 1)
		i += width_format(type, type.width - digits - 1, digits);
	i += hex_recursion(type.result.u_num_jug, type);
	if (type.flags.left == 1 && type.width > i)
		i += width_format(type, type.width - i, digits);
	return (i);
}
