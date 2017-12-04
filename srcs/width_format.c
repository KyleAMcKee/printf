/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:22:26 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/04 12:01:52 by kmckee           ###   ########.fr       */
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

int	display_sign(t_type type)
{
	int i;

	i = 0;
	if (type.flags.plus == 1 || type.result.num_jug < 0 || type.flags.space == 1)
	{
		if (type.flags.plus == 1 && type.result.num_jug >= 0)
		{
			ft_putchar('+');
			i++;
		}
		else if (type.flags.space == 1 && type.result.num_jug >= 0)
		{
			if (!type.flags.right)
			{
				ft_putchar(' ');
				i++;
			}
		}
		else
		{
			ft_putchar('-');
			i++;
		}
	}
	return (i);
}

int	justify(t_type type, int digits)
{
	int total;
	int i;

	i = 0;
	total = 0;
	digits++;
	while (total < type.width)
	{
		ft_putchar(' ');
		i++;
		total++;
	}
	return (i);
}

int	print_zeros(t_type type, int digits)
{
	int i;

	i = 0;
	digits++;
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

int	prepend_zero(t_type type, int digits)
{
	int i;

	i = 0;
	if (type.w_precision || type.flags.zero)
	{
		if (type.width || type.flags.zero == 1)
		{
			i += print_zeros(type, digits);
		}
	}
	return (i);
}

int	prepend_space(t_type type, int digits)
{
	int i;

	i = 0;
	if (type.flags.right == 1 )
		i += justify(type, digits);
	return (i);
}


