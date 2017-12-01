/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 22:51:16 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/30 23:25:07 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	u_arg_conversion(t_type type, va_list ap)
{

	//if (type.type >= 65 && type.type <= 90)
	//	type.length.l = 1;
	if (type.length.l == 1 || type.type == 'p' || type.type == 'U')
		type.result.u_num_jug = va_arg(ap, unsigned long);
	else if (type.length.ll == 1)
		type.result.u_num_jug = va_arg(ap, unsigned long long);
	else if(type.length.h == 1)
		type.result.u_num_jug = (unsigned short)va_arg(ap, unsigned int);
	else if (type.length.hh == 1)
		type.result.u_num_jug = (unsigned char)va_arg(ap, unsigned int);
	else if (type.length.z == 1)
		type.result.u_num_jug = va_arg(ap, size_t);
	else if (type.length.j == 1)
		type.result.u_num_jug = va_arg(ap, uintmax_t);
	else
		type.result.u_num_jug = va_arg(ap, unsigned int);
	return (type);
}

t_type	arg_conversion(t_type type, va_list ap)
{

	if (type.length.l == 1)
		type.result.u_num_jug = va_arg(ap, long);
	else if (type.length.ll == 1)
		type.result.u_num_jug = va_arg(ap, long long);
	else if(type.length.h == 1)
		type.result.u_num_jug = (short)va_arg(ap, int);
	else if (type.length.hh == 1)
		type.result.u_num_jug = (char)va_arg(ap, int);
	else if (type.length.z == 1)
		type.result.u_num_jug = va_arg(ap, size_t);
	else if (type.length.j == 1)
		type.result.u_num_jug = va_arg(ap, intmax_t);
	else if (type.type == 'C')
		type.result.chr = va_arg(ap, wchar_t);
	else if (type.type == 's')
		type.result.str = va_arg(ap, char*);
	else
		type.result.u_num_jug = va_arg(ap, int);
	return (type);
}
