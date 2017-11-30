/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:53:09 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/29 16:23:41 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_recursion(uintmax_t val)
{
	char dec[11];
	static int i;

	i = 0;
	ft_strcpy(dec, DEC);
	if (val == 0)
		return (1);
	if (val > 0)
	{
		unsigned_recursion(val / 10);
		ft_putchar(dec[val % 10]);
		i++;
	}
	return (i);
}


int	unsigned_format(t_type type, va_list ap)
{
	int i;
	int digits;
	uintmax_t temp;

	type = u_arg_conversion(type, ap);
	i = 0;
	digits = 0;
	temp = type.result.u_num_jug;
	while(temp /= 10)
		digits++;
	//ft_printf("digits: %d\n", digits);
	if (type.width > digits && type.flags.left != 1)
		i += width_format(type, type.width - digits - 1, digits);
	/*if (type.flags.zero == 1)
	{
		ft_putchar ('0');
		i++;
	}*/
	if (type.result.u_num_jug == 0)
		ft_putchar('0');
	i += unsigned_recursion(type.result.u_num_jug);
	if (type.flags.left == 1)
		i += width_format_after(type, type.width - i);
	//print_status(type);
	return (i);
}
