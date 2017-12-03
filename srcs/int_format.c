/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:34:19 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/03 14:50:43 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	set_flags(t_type type, int len)
{
//	if (type.flags.precision && type.w_precision <= len)
//		type.flags.zero = 0;
	type.width -= len;
	if (type.flags.left == 1)
	{
		type.flags.right = 0;
		type.flags.zero = 0;
	}
	if (type.flags.zero == 1)
		type.flags.right = 0;
	if (type.w_precision > type.width)
		type.width = 0;
	if (type.result.num_jug < 0 || type.flags.plus)
		type.width--;
	if (type.w_precision > len)
		type.w_precision -= len;
	else
		type.w_precision = 0;
	type.width -= type.w_precision;
	return (type);
}

int	num_len(intmax_t val)
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

int	int_format(t_type type, va_list ap)
{
	int total;
	int digits;

	type = arg_conversion(type, ap);
	digits = num_len(type.result.num_jug);
	total = digits;
	type = set_flags(type, digits);
	//print_status(type);
	total += prepend_space(type, digits);
	total += display_sign(type);
	total += prepend_zero(type, digits);
//	print_status(type);
//	if (!type.width && !type.w_precision)
//		i += display_sign(type);
	if (type.flags.precision == 1 && type.w_precision == 0 && type.result.num_jug == 0)
		return (type.width > 0 ? total - 1 : 0);
	print_max(type.result.num_jug);
	if (type.flags.left == 1)
		total += right_justify(type, total);
	return (total);
}
