/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:34:19 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/05 18:09:20 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			display_sign(t_type type)
{
	int i;

	i = 0;
	if (type.flags.plus == 1 || type.res.num < 0 || type.flags.space == 1)
	{
		if (type.flags.plus == 1 && type.res.num >= 0)
		{
			ft_putchar('+');
			i++;
		}
		else if (type.flags.space == 1 && type.res.num >= 0)
		{
			if (!type.flags.right)
			{
				ft_putchar(' ');
				i++;
			}
		}
		else
		{
			ft_putchar('-');
			i++;
		}
	}
	return (i);
}

t_type		set_flags_int(t_type type, int len)
{
	if (type.flags.left == 1)
		type.flags.right = 0;
	if (type.flags.zero == 1)
		type.flags.right = 0;
	if (type.w_precision > type.width)
		type.flags.right = 0;
	if (type.w_precision > type.width)
		type.width = 0;
	if (type.res.num < 0 || type.flags.plus)
		type.width--;
	if (len > type.w_precision)
		type.width -= len;
	else
		type.width -= type.w_precision;
	if (type.w_precision > len)
		type.w_precision -= len;
	else
		type.w_precision = 0;
	if (len >= type.w_precision && type.flags.zero && type.flags.precision)
		type.flags.right = 1;
	if (type.flags.space == 1 && type.flags.zero == 1)
		type.width--;	
	return (type);
}

int			num_len(intmax_t val)
{
	int i;

	i = 0;
	if (val < 0)
		val *= -1;
	else if (val == 0)
		return (1);
	while (val)
	{
		val /= 10;
		i++;
	}
	return (i);
}

int			int_format(t_type type, va_list ap)
{
	int total;
	int digits;

	type = arg_conversion(type, ap);
	digits = num_len(type.res.num);
	total = digits;
	type = set_flags_int(type, digits);
	total += prepend_space(type);
	total += display_sign(type);
	total += prepend_zero(type);
	//print_status(type);
	if (type.flags.precision == 1 && type.w_precision == 0 && type.res.num == 0)
	{
		type.width > 0 ? ft_putchar(' ') : 0;
		return (type.width > 0 ? total : 0);
	}
	print_max(type.res.num);
	if (type.flags.left == 1)
		total += justify(type);
	return (total);
}
