/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:39:24 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/06 19:15:26 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	t_pos	pos;
	t_type	type;

	pos.i = 0;
	pos.start = 0;
	va_start(ap, format);
	type.ret = 0;
	while (format[pos.i] != '\0')
		if (format[pos.i] == '%')
		{
			write(1, &format[pos.start], pos.i - pos.start);
			type.ret += (pos.i++ - pos.start);
			type = check_flags(format, type, &pos.i, ap);
			if (!type.type)
				return (type.ret);
			type.ret += type_handler(type, ap);
			pos.start = pos.i;
		}
		else if (format[pos.i] != '\0')
			pos.i++;
	write(1, &format[pos.start], pos.i - pos.start);
	type.ret += (pos.i - pos.start);
	va_end(ap);
	return (type.ret);
}
