/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:43:40 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/03 23:12:52 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_print(uintmax_t val, t_type type)
{
	char		hex[33];
	static int	i;

	i = 0;
	ft_strcpy(hex, HEX);
	if (val == 0)
		return (1);
	if (val > 0)
	{
		pointer_print(val / 16, type);
		ft_putchar(hex[val % 16]);
		i++;
	}
	return (i);
}

int	pointer_format(t_type type, va_list ap)
{
	uintmax_t	val;
	int			i;

	i = 2;
	type = u_arg_conversion(type, ap);
	val = type.result.u_num_jug;
	ft_putstr("0x");
	if (val == 0)
		ft_putchar('0');
	i += pointer_print(val, type);
	return (i);
}
	
