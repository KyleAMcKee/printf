/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:53:09 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 19:30:41 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_recursion(uintmax_t val)
{
	char		dec[11];
	static int	i;

	i = 0;
	ft_strcpy(dec, DEC);
	if (val == 0)
		return (1);
	if (val > 0)
	{
		unsigned_recursion(val / 10);
		ft_putchar(dec[val % 10]);
		i++;
	}
	return (i);
}

int		u_num_len(uintmax_t val)
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

t_type	set_unsigned_flags(t_type type, int len)
{
	if (type.flags.left == 1)
		type.flags.right = 0;
	if (type.flags.zero == 1)
		type.flags.right = 0;
	if (type.w_precision > type.width)
		type.width = 0;
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

int	unsigned_format(t_type type, va_list ap)
{
	int			total;
	int			digits;
	int			ret;

	total = 0;
	type = u_arg_conversion(type, ap);
	digits = u_num_len(type.res.num);
	type = set_unsigned_flags(type, digits);
	total += prepend_space(type);
	total += prepend_zero(type);
	if (type.flags.precision == 1 && type.w_precision == 0 && type.res.unum == 0)
		return (total);
	ret = unsigned_recursion(type.res.unum);
	if (ret == 1 && type.res.unum == 0)
		ft_putchar('0');
	total += ret;
	if (type.flags.left == 1)
		total += justify(type);
	return (total);
}
