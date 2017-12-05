/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:53:09 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 16:31:21 by kmckee           ###   ########.fr       */
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

int	width_format(t_type type, int amount)
{
	int ret;

	ret = 0;
	while (amount)
	{
		if (type.flags.zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		amount--;
		ret++;
	}
	return (ret);
}

int	width_format_after(t_type type, int amount)
{
	int ret;

	ret = 0;
	if (type.flags.left == 1)
	{
		while (amount)
		{
			ft_putchar(' ');
			amount--;
			ret++;
		}
	}
	return (ret);
}

int	prepend_zeros(t_type type, int digits)
{
	int i;

	i = 0;
	while (--type.w_precision > digits)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

int	unsigned_format(t_type type, va_list ap)
{
	int			i;
	int			digits;
	uintmax_t	temp;

	type = u_arg_conversion(type, ap);
	i = 0;
	digits = 0;
	temp = type.res.unum;
	while (temp /= 10)
		digits++;
	if (type.width > digits && type.flags.left != 1)
		i += width_format(type, type.width - digits - 1);
	if (type.w_precision > digits)
		i += prepend_zeros(type, digits);
	if (type.res.unum == 0)
		ft_putchar('0');
	i += unsigned_recursion(type.res.unum);
	if (type.flags.left == 1)
		i += width_format_after(type, type.width - i);
	return (i);
}
