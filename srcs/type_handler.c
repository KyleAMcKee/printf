/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 21:02:32 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/05 15:40:26 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_error_handler(t_type type)
{
	if (type.type == 'C' && type.length.hh == 1)
		return (1);
	return (0);
}

int	type_handler(t_type type, va_list ap)
{
	if (type_error_handler(type))
		return (-1);
	if (type.type == '%')
		return (percent_format(type));
	else if ((type.type == 'c' && type.length.l != 1) || type.type == 'C') 
		return (char_format(type, ap));
	else if ((type.type == 'c' && type.length.l == 1))
		return (wchar_format(type, ap));
	else if ((type.type == 's' && type.length.l == 1))
		return (wchar_string_format(type, ap));
	else if (type.type == 's' || type.type == 'S')
		return (string_format(type, ap));
	else if (type.type == 'i' || type.type == 'd' || type.type == 'D')
		return (int_format(type, ap));
	else if (type.type == 'x' || type.type == 'X')
		return (hex_format(type, ap));
	else if (type.type == 'o' || type.type == 'O')
		return (octal_format(type, ap));
	else if (type.type == 'u' || type.type == 'U')
		return (unsigned_format(type, ap));
	else if (type.type == 'p')
		return (pointer_format(type, ap));
	else
		return (0);
	return (0);
}
