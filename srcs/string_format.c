/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:16:39 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/01 19:35:06 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	left_justify(t_type type, int length)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	if (length > type.w_precision)
		total += length;
	else
		total += type.w_precision;
	while (total < type.width)
	{
		ft_putchar(' ');
		i++;
		total++;
	}
	return (i);
}

int	string_zero_pad(t_type type, int length)
{
	int	total;
	int	i;

	i = 0;
	total = 0;
	if (type.flags.right || type.flags.left)
		return (i);
	else
		while (type.width > length)
		{
			ft_putchar('0');
			type.width--;
			i++;
		}
	return (i);
}

int	string_format(t_type type, va_list ap)
{
	int		len;
	int		total;
	int 	i;

	total = 0;
	i = 0;
	type = arg_conversion(type, ap);
	if (type.result.str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = (int)ft_strlen(type.result.str);
	total += string_zero_pad(type, len);
	if (type.flags.right == 1 && type.width > len)
		total = width_format(type, type.width - len + (len ? type.w_precision : 0), len);
	if (ft_strequ(type.result.str, ""))
	{
		if (type.flags.left == 1)
			total = width_format(type, type.width, len);
			return (total);
	}
	if (type.flags.precision == 1)
	{
		while (i < type.w_precision)
		{
			ft_putchar(type.result.str[i]);
			i++;
		}
		total += i;
		len = i;
	}
	else
	{
		ft_putstr(type.result.str);
		total += len;
	}
	if (type.flags.left == 1 && type.width > len)
		 total += left_justify(type, len);
	//print_status(type);
	return (total);
}
