/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:34:19 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/30 11:13:33 by kmckee           ###   ########.fr       */
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

int	display_sign(t_type type)
{
	int i;

	i = 0;
	if (type.flags.plus == 1 || type.result.num_jug < 0 || type.flags.space == 1)
	{
		if (type.flags.plus == 1 && type.result.num_jug >= 0)
		{
			ft_putchar('+');
			i++;
		}
		else if (type.flags.space == 1 && type.result.num_jug >= 0)
		{
			if (!type.width)
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

int	right_justify(t_type type, int digits)
{
	int total;
	int i;

	i = 0;
	total = type.flags.plus;
	if (digits < type.w_precision)
		total += type.w_precision;
	else
		total += digits;
	if (type.result.num_jug < 0)
		total++;
	while (total < type.width)
	{
		ft_putchar(' ');
		i++;
		total++;
	}
	return (i);
}

int	prepend_space(t_type type, int digits)
{
	int i;

	i = 0;
	if ((type.width || type.w_precision) && !type.flags.zero)
	{
		if (type.width > type.w_precision && !type.flags.left)
			i += right_justify(type, digits);
		i += display_sign(type);
		if (type.width < type.w_precision || digits < type.w_precision)
		{
			while (type.w_precision-- > digits)
			{
				ft_putchar('0');
				i++;
			}
		}
	}
	return (i);
}

int	prepend_zero(t_type type, int digits)
{
	int i;

	i = 0;
	if ((type.width || type.w_precision) && type.flags.zero)
	{
		if (type.w_precision && type.width > type.w_precision && !type.flags.left)
			i += right_justify(type, digits);
		if ((i += display_sign(type)))
			digits++;
		if (digits < type.width || digits < type.w_precision)
		{
			if (digits < type.width)
			{
				while (type.width-- > digits)
				{
					ft_putchar('0');
					i++;
				}
			}
			else
				while (type.w_precision-- > digits)
				{
					ft_putchar('0');
					i++;
				}
		}
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
	i += prepend_space(type, total);
	i += prepend_zero(type, total);
	if (!type.width && !type.w_precision)
	{
		i += display_sign(type);
	}
	print_max(type.result.num_jug);
	if (type.flags.left == 1)
		i += right_justify(type, total);
	return (i);
}
