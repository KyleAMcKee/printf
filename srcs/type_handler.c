/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:02:32 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 15:21:50 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_handler(t_type type, va_list ap)
{
	ft_putchar('#');
	if (type.type == '%')
		return (percent_format(type));
	if (type.type == 'c' && type.length.l != 1)
		return (char_format(type, ap)); 
	if (type.type == 'C' || (type.type == 'c' && type.length.l == 1))
		return (wchar_format(type, ap));
	if (type.type == 's')
		return (string_format(type, ap));
	if (type.type == 'S')
	{
		ft_putchar('%');
		return (wchar_string_format(type, ap));
	}
	if (type.type == 'i' || type.type == 'd' || type.type == 'D')
		return (int_format(type, ap));
	if (type.type == 'x' || type.type == 'X')
		return (hex_format(type, ap));
	if (type.type == 'o' || type.type == 'O')
		return (octal_format(type, ap));
	if (type.type == 'u' || type.type == 'U')
		return (unsigned_format(type, ap));
	if (type.type == 'p')
		return (pointer_format(type, ap));
	return (0);
}
