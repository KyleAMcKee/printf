/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:34:19 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/01 18:23:29 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int i;

	type = arg_conversion(type, ap);
	total = num_len(type.result.num_jug);
	i = total;
	if (type.flags.precision && type.w_precision <= i)
		type.flags.zero = 0;
	i += prepend_space(type, total);
	i += prepend_zero(type, total);
	if (!type.width && !type.w_precision)
	{
		i += display_sign(type);
	}
	if (type.flags.precision == 1 && type.w_precision == 0 && type.result.num_jug == 0)
		return (type.width > 0 ? i - 1 : 0);
	print_max(type.result.num_jug);
	if (type.flags.left == 1)
		i += right_justify(type, total);
	//print_status(type);
	return (i);
}
