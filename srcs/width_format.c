/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:22:26 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/29 16:33:28 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	width_format(t_type type, int amount, int places)
{
	int ret;

	ret = 0;
	while (amount)
	{
		if (type.flags.zero == 1)
			ft_putchar('0');
		else if (type.flags.precision == 1 && (type.type == 'o' || type.type == 'O'))
			if (type.w_precision > places)
				ft_putchar('0');
			else
				ft_putchar(' ');			
		else
			ft_putchar(' ');
		amount--;
		ret++;
	}
	return (ret);
}

int width_format_after(t_type type, int amount)
{
	int ret;

	ret = 0;
	if (type.flags.left == 1)
	{
		while (amount)
		{
			ft_putchar(' ');
			amount--;
			ret++;
		}
	}
	return (ret);
}
