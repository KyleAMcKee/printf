/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:02:32 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/01 20:26:24 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_handler(t_type type, va_list ap)
{
	if (type.type == '%')
		return (percent_format(type));
	if (type.type == 'c' && type.length.l != 1)
		return (char_format(type, ap)); 
	if (type.type == 'C' || (type.type == 'c' && type.length.l == 1))
		return (wchar_format(type, ap));
	if (type.type == 's')
		return (string_format(type, ap));
	if	(type.type == 'S')
	{
	//	ft_putstr("oo0o0o0o\n");
		return (wchar_string_format(type, ap));
	}
	if (type.type == 'i' || type.type == 'd')
		return (int_format(type, ap));
	if (type.type == 'D')
	{
		type.length.l = 1;
		return (int_format(type, ap));
	}
	if (type.type == 'x' || type.type == 'X')
		return (hex_format(type, ap));
	if (type.type == 'o' || type.type == 'O')
		return (octal_format(type, ap));
	if (type.type == 'u' || type.type == 'U')
		return (unsigned_format(type, ap));
	if (type.type == 'p')
		return (pointer_format(type, ap));
//	ft_putstr("not a valid type\n");
	return (0);
}
