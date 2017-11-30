/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 14:39:24 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/29 12:06:46 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i;
	int		start;
	t_type	type;

	i = 0;
	start = 0;
	va_start(ap, format);
	type.ret = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			write(1, &format[start], i - start);
			type.ret += (i++ - start);
			type = check_flags(format, type, &i);
			type.ret += type_handler(type, ap);
			start = i;
		}
		else if (format[i] != '\0') 
			i++;
	}
	write(1, &format[start], i - start);
	type.ret += (i - start);
	va_end(ap);
	return (type.ret);
}
