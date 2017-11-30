/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:01:15 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/29 13:26:58 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	char_format(t_type type, va_list ap)
{
	char c;
	int total;

	c = va_arg(ap, int);
	total = 0;
	if (type.flags.right == 1 && type.width > 1)
		total = width_format(type, type.width - 1, 1);
	ft_putchar(c);
	total++;
	if (type.flags.left == 1 && type.width > 1)
		total += width_format(type, type.width - 1, 1);
	return (total);
}
