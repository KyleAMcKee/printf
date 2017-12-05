/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:01:15 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 16:30:49 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_format(t_type type, va_list ap)
{
	int total;

	type.flags.plus = 0;
	type.w_precision = 0;
	type = arg_conversion(type, ap);
	total = 1;
	type.width--;
	total += prepend_space(type, total);
	total += prepend_zero(type, total);
	ft_putchar(type.res.chr);
	if (type.flags.left == 1)
		total += justify(type, total);
	return (total);
}
