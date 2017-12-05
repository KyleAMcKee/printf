/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:51:16 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 16:30:46 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	char_conversion(t_type type, va_list ap)
{
	if (type.type == 'C')
		type.res.chr = va_arg(ap, wchar_t);
	else if (type.type == 'S')
		type.res.wstr = va_arg(ap, wchar_t*);
	return (type);
}

t_type	u_arg_conversion(t_type type, va_list ap)
{
	if (type.type == 'p' || type.type == 'U' || type.type == 'O')
		type.res.unum = va_arg(ap, unsigned long);
	else if (type.length.l == 1)
		type.res.unum = va_arg(ap, unsigned long);
	else if (type.length.ll == 1)
		type.res.unum = va_arg(ap, unsigned long long);
	else if (type.length.h == 1)
		type.res.unum = (unsigned short)va_arg(ap, unsigned int);
	else if (type.length.hh == 1)
		type.res.unum = (unsigned char)va_arg(ap, unsigned int);
	else if (type.length.z == 1)
		type.res.unum = va_arg(ap, size_t);
	else if (type.length.j == 1)
		type.res.unum = va_arg(ap, uintmax_t);
	else
		type.res.unum = va_arg(ap, unsigned int);
	return (type);
}

t_type	arg_conversion(t_type type, va_list ap)
{
	if (type.length.l == 1 || type.type == 'D')
		type.res.num = va_arg(ap, long);
	else if (type.length.ll == 1)
		type.res.num = va_arg(ap, long long);
	else if (type.length.h == 1)
		type.res.num = (short)va_arg(ap, int);
	else if (type.length.hh == 1)
		type.res.num = (char)va_arg(ap, int);
	else if (type.length.z == 1)
		type.res.num = va_arg(ap, size_t);
	else if (type.length.j == 1)
		type.res.num = va_arg(ap, intmax_t);
	else if (type.type == 's')
		type.res.str = va_arg(ap, char*);
	else
		type.res.num = va_arg(ap, int);
	return (type);
}
