/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:43:40 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/05 23:20:26 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pointer_print(uintmax_t val, t_type type)
{
	char		hex[33];
	static int	i;

	i = 0;
	ft_strcpy(hex, HEX);
	if (val == 0)
		return (1);
	if (val > 0)
	{
		pointer_print(val / 16, type);
		ft_putchar(hex[val % 16]);
		i++;
	}
	return (i);
}

int		pointer_len(uintmax_t val)
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

t_type	set_flags_pointer(t_type type, int len)
{
	type.width -= len;
	if (type.flags.left == 1)
		type.flags.right = 0;
	if (type.flags.zero == 1)
		type.flags.right = 0;
	if (type.w_precision > type.width)
		type.width = 0;
	if (type.w_precision > len)
		type.w_precision -= len;
	else
		type.w_precision = 0;
	if (type.res.unum == 0)
		type.width--;
	type.width -= type.w_precision;
	type.width -= 2;
	return (type);
}

int		pointer_format(t_type type, va_list ap)
{
	int	len;
	int	total;

	total = 2;
	type = u_arg_conversion(type, ap);
	len = pointer_len(type.res.unum);
	type = set_flags_pointer(type, len);
	total += prepend_space(type);
	ft_putstr("0x");
	total += prepend_zero(type);
	if (type.flags.precision == 1
		&& type.w_precision == 0 && type.res.unum == 0)
		return (total);
	if (type.res.unum == 0 && !type.w_precision)
	{
		total++;
		ft_putchar('0');
	}
	if (type.res.unum > 0)
		total += pointer_print(type.res.unum, type);
	if (type.flags.left == 1)
		total += justify(type);
	return (total);
}
