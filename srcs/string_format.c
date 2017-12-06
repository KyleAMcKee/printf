/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:16:39 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/05 23:18:39 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		string_zero_pad(t_type type, int length)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	length++;
	if (type.flags.right || type.flags.left)
		return (i);
	else
		while (type.width > 0)
		{
			ft_putchar('0');
			type.width--;
			i++;
		}
	return (i);
}

t_type	set_string_flags(t_type type, int len)
{
	if (type.flags.left == 1)
		type.flags.right = 0;
	if (type.flags.zero == 1)
		type.flags.right = 0;
	if (len > type.width && !type.w_precision)
		type.width = 0;
	if (type.w_precision > len)
	{
		type.w_precision = len;
		type.width -= len;
	}
	else if (type.w_precision < len)
	{
		type.width -= type.w_precision;
	}
	else
		type.width -= type.w_precision;
	if (!type.flags.precision && type.width > len)
		type.width -= len;
	return (type);
}

int		print_str(t_type type, int len)
{
	int i;

	i = 0;
	if (type.flags.precision == 1 && !ft_strequ(type.res.str, ""))
	{
		while (i < type.w_precision)
		{
			ft_putchar(type.res.str[i]);
			i++;
		}
		return (i);
	}
	else
		ft_putstr(type.res.str);
	return (len);
}

int		string_format(t_type type, va_list ap)
{
	int		len;
	int		total;

	total = 0;
	len = 0;
	type = arg_conversion(type, ap);
	if (type.res.str == NULL && !type.width)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (type.res.str)
		len = (int)ft_strlen(type.res.str);
	type = set_string_flags(type, len);
	total += string_zero_pad(type, len);
	total += prepend_space(type);
	total += print_str(type, len);
	if (type.flags.left == 1)
		total += justify(type);
	return (total);
}
