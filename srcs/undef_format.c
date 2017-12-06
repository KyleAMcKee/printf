/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undef_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:17:25 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/05 18:00:34 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	set_flags_undef(t_type type)
{
	if (type.flags.left == 1)
		type.flags.right = 0;
	if (type.flags.zero == 1)
		type.flags.right = 0;
	if (type.type)
		type.width--;
	return (type);
}

int	undef_format(t_type type)
{
	int total;
	
	total = 0;
	//print_status(type);
	type = set_flags_undef(type);
	total += prepend_space(type);
	total += prepend_zero(type);
	if (type.type)
	{
		ft_putchar(type.type);
		total++;
	}
	if (type.flags.left == 1)
		total += justify(type);
	return (total);
}
