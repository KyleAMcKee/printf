/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:14:59 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/29 13:31:23 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percent_format(t_type type)
{
	int align;
	int ret;

	align = type.width;
	if (align > 1 && type.flags.left == 0)
		ret = width_format(type, align - 1, 1);
	ft_putchar('%');
	if (align > 1 && type.flags.left == 1)
		ret = width_format(type, align - 1, 1);
	if (type.width > 1)
		return (type.width);
	else
		return (1);
}

