/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:16:51 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/01 21:06:32 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	wchar_convert(wchar_t c)
{
	char *str;

	str = NULL;
	if (c <= 0x80)
	{
		str = ft_strnew(1);
		str[0] = c;
	}
	else if (c <= 0x7FF)
	{
		str = ft_strnew(2);
		str[0] = (c >> 6) | 0xC0;
		str[1] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0xFFFF)
	{
		
		str = ft_strnew(3);
		str[0] = c >> 12 | 0xE0;
		str[1] = (c >> 6 & 0x3F) | 0x80;
		str[2] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		str = ft_strnew(4);
		str[0] = c >> 18 | 0xF0;
		str[1] = (c >> 12 & 0x3F) | 0x80;
		str[2] = (c >> 6 & 0x3F) | 0x80;
		str[3] = (c & 0x3F) | 0x80;
	}
	ft_putstr(str);
	free(str);
}

int		wchar_format(t_type type, va_list ap)
{
	type = u_arg_conversion(type, ap);
	wchar_convert(type.result.chr);
	return (1);
}

int		wchar_string_format(t_type type, va_list ap)
{
	int i;

	i = 0;
	type = u_arg_conversion(type, ap);
	while (type.result.wstr[i])
	{
		if (type.result.wstr[i] >> 8)
			wchar_convert(type.result.wstr[i]);
		else
			ft_putchar(type.result.wstr[i]);
		i++;	
	}
	return (i);
}
