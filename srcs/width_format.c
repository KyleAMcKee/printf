/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:22:26 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 19:01:03 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	justify(t_type type)
{
	int total;

	total = 0;
	while (total < type.width)
	{
		ft_putchar(' ');
		total++;
	}
	return (total);
}

int	print_zeros(t_type type)
{
	int i;

	i = 0;
	if (!type.flags.right && !type.flags.left)
	{
		while (type.width > i)
		{
			ft_putchar('0');
			i++;
		}
	}
	while (type.w_precision > i)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}

int	prepend_zero(t_type type)
{
	int i;

	i = 0;
	if (type.w_precision || type.flags.zero)
	{
		if (type.width || type.flags.zero == 1)
		{
			i += print_zeros(type);
		}
	}
	return (i);
}

int	prepend_space(t_type type)
{
	int i;

	i = 0;
	if (type.flags.right == 1)
		i += justify(type);
	return (i);
}
