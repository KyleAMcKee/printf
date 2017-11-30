/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:30:27 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/29 14:36:53 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int octal_recursion(uintmax_t val)
{
	char oct[9];
	static int i;

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

int octal_format(t_type type, va_list ap)
{
	uintmax_t temp;
	int digits;	
	int i;
	int adjust;

	type = u_arg_conversion(type, ap);
	temp = type.result.u_num_jug;
	digits = 0;
	i = 0;
	adjust = 0;
	if (type.flags.precision == 1 && type.result.u_num_jug == 0)
	{
		if (type.flags.hash == 1)
		{
			ft_putchar('0');
			i++;
		}
		while (i < type.width)
		{
			ft_putchar(' ');
			i++;
		}
		return (i);
	}
	while (temp /= 10)
		digits++;
	digits = digits + type.flags.hash;
	if (type.flags.right == 1 && type.width > digits)
		i += width_format(type, type.width - digits - 1, digits);
	if (type.flags.hash == 1 )//&& type.result.u_num_jug > 0)
	{
		ft_putchar('0');
		i++;
		if (type.result.u_num_jug == 0)
			return (i);
	}
	if (type.w_precision > digits && type.flags.precision == 1 && type.result.u_num_jug >0)
	{
		adjust = width_format(type, type.w_precision - digits - 1, digits);
		i += adjust;
	}
	if (type.width > digits && type.flags.zero == 1)
		i += width_format(type, type.width - digits - 1, digits);
	i += octal_recursion(type.result.u_num_jug);
	if (type.result.u_num_jug == 0)
		ft_putchar('0');
	if (type.flags.left == 1 && type.width > i)
		i += width_format_after(type, type.width - digits - 1 - adjust);
	return(i);
}
