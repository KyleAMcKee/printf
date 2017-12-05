/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 15:32:55 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 16:30:51 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conv(char c, t_type type)
{
	char	types[16];
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

t_type	check_check(const char *str, t_type type, int *i)
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
		*i += 1;
	}
	return (type);
}

t_type	check_flags(const char *str, t_type type, int *i)
{
	type = clear_flags(type);
	type = check_check(str, type, i);
	type = check_length(str, type, i);
	type = check_check(str, type, i);
	type.type = str[*i];
	if (check_conv(type.type, type) == -1 && ft_isalpha(type.type))
	{
		if (!is_len(type.type))
		{
			ft_putchar(type.type);
			type.ret++;
		}
	}
	*i += 1;
	return (type);
}
