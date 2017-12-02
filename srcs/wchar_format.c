/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:16:51 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/01 20:32:52 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
char	*wchar_convert(wchar_t c, char *str)
{
	if (c <= 0x80)
	{
		str = ft_strnew(1);
		str[0] = c;
	}
	else if (c <= 0x7FF)
	{
		str = (char*)malloc(sizeof(unsigned char) *2 + 1);
		str[0] = (c >> 6) | 0xC0;
		str[1] = (c & 0x3F) | 0x80;
		str[2] = '\0';
	}
	else if (c <= 0xFFFF)
	{
		
		str = (char*)malloc(sizeof(unsigned char) * 3 + 1);
		//str = ft_strnew(3);
		str[0] = c >> 12 | 0xE0;
		str[1] = (c >> 6 & 0x3F) | 0x80;
		str[2] = (c & 0x3F) | 0x80;
		str[3] = '\0';
	}
	else if (c <= 0x10FFFF)
	{
		str = (char*)malloc(sizeof(unsigned char) * 4 + 1);
		//str = ft_strnew(4);
		str[0] = c >> 18 | 0xF0;
		str[1] = (c >> 12 & 0x3F) | 0x80;
		str[2] = (c >> 6 & 0x3F) | 0x80;
		str[3] = (c & 0x3F) | 0x80;
		str[4] = '\0';
	}
//	ft_putstr(str);
	return (str);
}

int	wchar_format(t_type type, va_list ap)
{
	char *str;
	
	str = NULL;
	type = u_arg_conversion(type, ap);
	str = wchar_convert(type.result.chr, str);
	ft_putstr(str);
	return (1);
}

int	wchar_string_format(t_type type, va_list ap)
{
	wchar_t *wstr;
	char	*str;
	int i;

	i = 0;
	wstr = va_arg(ap, wchar_t*);
	type.type = 'S';
	while (wstr[i])
	{
		if (wstr[i] >> 8)
		{
			str = wchar_convert(wstr[i], str);
			ft_putstr(str);
		}
		else
			ft_putchar(wstr[i]);
		i++;	
	}
	return (i);
}




