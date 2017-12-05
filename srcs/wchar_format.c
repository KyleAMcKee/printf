/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:16:51 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 16:51:36 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*big_bytes(char *str, int c, int *i)
{
	if (c <= 0xFFFF)
	{
		str[0] = (c >> 12) | 0xE0;
		str[1] = ((c >> 6) & 0x3F) | 0x80;
		str[2] = (c & 0x3F) | 0x80;
		i += 3;
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = (c >> 18) | 0xF0;
		str[1] = ((c >> 12) & 0x3F) | 0x80;
		str[2] = ((c >> 6) & 0x3F) | 0x80;
		str[3] = (c & 0x3F) | 0x80;
		i += 4;
	}
	return (str);
}

int		wchar_convert(int c)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(4);
	if (c <= 0x80)
	{
		i++;
		str[0] = c;
	}
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) | 0xC0;
		str[1] = (c & 0x3F) | 0x80;
		i += 2;
	}
	else if (c <= 0xFFFF)
		str = big_bytes(str, c, &i);
	else if (c <= 0x10FFFF)
		str = big_bytes(str, c, &i);
	ft_putstr(str);
	free(str);
	return (i);
}

int		wchar_format(t_type type, va_list ap)
{
	int i;

	i = 0;
	type = char_conversion(type, ap);
	i = wchar_convert(type.res.chr);
	return (i);
}

int		wchar_string_format(t_type type, va_list ap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	type = char_conversion(type, ap);
	if (!type.res.wstr)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (type.res.wstr[i])
	{
		j += wchar_convert(type.res.wstr[i]);
		i++;
	}
	return (j);
}
