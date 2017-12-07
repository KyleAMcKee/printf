/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:46:27 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/06 13:13:46 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_binary(uintmax_t number)
{
	static int total;

	total = 0;	
	if (number)
	{	
		print_binary(number >> 1);
		ft_putchar((number & 1) ? '1' : '0');
		total++;
	}
	return (total);
}
	

int	binary_format(t_type type, va_list ap)
{
	int total;

	total = 0;
	type = u_arg_conversion(type, ap);
	total = print_binary(type.res.unum);
	return (total);
}
