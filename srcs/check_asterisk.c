/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asterisk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 11:09:47 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/07 12:48:58 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	check_asterisk(t_type type, va_list ap)
{
	int temp;
	
	temp = va_arg(ap, int);
	if (temp < 0 && !type.flags.precision)
	{
		type.flags.left = 1;
		temp *= -1;
	}
	else if (temp <= 0 && type.flags.precision)
	{
		//temp *= -1;
		if (type.width)
			type.w_precision = type.width;
		else
			type.w_precision = temp;
	}
	if (temp >= 0)
		type.width = temp;
	if (type.flags.precision == 1 && temp > 0)
	{
		type.w_precision = type.width;
		type.width = 0;
	}
	if (!type.flags.zero && !type.flags.left)
		type.flags.right = 1;
	return (type);
}
