/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:25:58 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 16:30:55 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == '#' || c == '-' || c == '+' || c == '0' || c == ' ' || c == '.')
		return (1);
	return (0);
}

t_type	is_minus(const char *str, t_type type, int *i, int temp)
{
	type.flags.left = 1;
	type.flags.zero = 0;
	if (str[*i + 1] == '0')
		*i += 1;
	if (is_flag(str[*i + 1]) || (check_conv(str[*i + 1], type) >= 0))
		return (type);
	type.width = ft_atoi(&str[++*i]);
	temp = type.width;
	while (temp /= 10)
		*i += 1;
	return (type);
}

t_type	is_zero(const char *str, t_type type, int *i, int temp)
{
	type.width = ft_atoi(&str[*i]);
	temp = type.width;
	if (!type.flags.left && !type.flags.zero)
		type.flags.right = 1;
	while (temp /= 10)
		*i += 1;
	return (type);
}

t_type	check_width(const char *str, t_type type, int *i)
{
	int temp;

	temp = 0;
	if (ft_isdigit(str[*i]) && !type.width)
	{
		type = is_zero(str, type, i, temp);
		return (type);
	}
	if (str[*i] == '-')
		type = is_minus(str, type, i, temp);
	else if (str[*i] == '.')
	{
		type.flags.precision += 1;
		if (ft_isdigit(str[*i + 1]))
			type.w_precision = ft_atoi(&str[++*i]);
		else
		{
			type.w_precision = 0;
			return (type);
		}
		temp = type.w_precision;
		while (temp /= 10)
			*i += 1;
	}
	return (type);
}
