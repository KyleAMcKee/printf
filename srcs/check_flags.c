/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:32:55 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/07 13:03:16 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conv(char c, t_type type)
{
	char	types[18];
	int		i;

	i = 0;
	ft_strcpy(types, TYPES);
	while (types[i])
	{
		if (types[i] == c)
		{
			type.type = c;
			return (1);
		}
		i++;
	}
	return (-1);
}

t_type	clear_flags(t_type type)
{
	type.flags.hash = 0;
	type.flags.zero = 0;
	type.flags.left = 0;
	type.flags.right = 0;
	type.width = 0;
	type.w_precision = 0;
	type.flags.plus = 0;
	type.flags.space = 0;
	type.flags.precision = 0;
	type.flags.percent = 0;
	type.flags.asterisk = 0;
	type.length.h = 0;
	type.length.hh = 0;
	type.length.l = 0;
	type.length.ll = 0;
	type.length.j = 0;
	type.length.z = 0;
	return (type);
}

t_type	zero_padding(const char *str, t_type type, int *i)
{
	int temp;

	if (!type.flags.right && !type.flags.left)
		type.flags.zero += 1;
	if (!ft_isdigit(str[*i + 1]))
		return (type);
	type.width = ft_atoi(&str[++*i]);
	temp = type.width;
	while (temp /= 10)
		*i += 1;
	return (type);
}

t_type	check_modifiers(const char *str, t_type type, int *i, va_list ap)
{
	while (is_flag(str[*i]) || ft_isdigit(str[*i]))
	{
		if (str[*i] == '0' && !type.width)
			type = zero_padding(str, type, i);
		else if ((ft_isdigit(str[*i]) || str[*i] == '.' || str[*i] == '-'))
			type = check_width(str, type, i);
		else if (str[*i] == '#')
			type.flags.hash = 1;
		else if (str[*i] == '+')
			type.flags.plus = 1;
		else if (str[*i] == ' ')
			type.flags.space = 1;
		else if (str[*i] == '*')
		{
			type.flags.asterisk = 1;
			type = check_asterisk(type, ap);
		}
		//print_status(type);
		*i += 1;
	}
	return (type);
}

t_type	check_flags(const char *str, t_type type, int *i, va_list ap)
{
	type = clear_flags(type);
	type = check_modifiers(str, type, i, ap);
	type = check_length(str, type, i);
	type = check_modifiers(str, type, i, ap);
	type.type = str[*i];
	if ((check_conv(type.type, type) == -1 && ft_isalpha(type.type))
		|| type.type == '}')
	{
		if (!is_len(type.type))
		{
			type.ret += undef_format(type);
		}
	}
	if (type.flags.asterisk == 1 && type.type == 's' && type.w_precision < 0)
		type = clear_flags(type);
//	print_status(type);
	*i += 1;
	return (type);
}

