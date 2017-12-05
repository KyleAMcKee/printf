
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:14:59 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 16:31:11 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	percent_format(t_type type)
{
	int ret;

	ret = 0;
	if (type.width > 1 && type.flags.left == 0)
	{
		type.width--;
		ret += prepend_space(type);
	}
	if (type.width > 1  && type.flags.zero == 1)
	{
		ret += prepend_zero(type);
	}
	ft_putchar('%');
	ret += 1;
	if (type.width > 1 && type.flags.left == 1)
	{
		type.width--;
		ret += justify(type);
	}
	if (type.width > 1)
		return (ret);
	else
		return (1);
}
