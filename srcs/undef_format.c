/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undef_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:17:25 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 21:57:27 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_type	set_flags_undef(t_type type)
{
	type.width--;
	return (type);
}

int	undef_format(t_type type)
{
	int total;
	
	total = 0;
	type = set_flags_undef(type);
	total += prepend_space(type);
	total += prepend_zero(type);
	ft_putchar(type.type);
	total++;
	return (total);
}
