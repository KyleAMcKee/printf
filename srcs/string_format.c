/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <kmckee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:16:39 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/30 23:02:31 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	string_format(t_type type, va_list ap)
{
//	char	*str;
	int		len;
	int		total;
	int 	i;

	total = 0;
	i = 0;
	type = arg_conversion(type, ap);
	if (type.result.str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = (int)ft_strlen(type.result.str);
	if (type.flags.right == 1 && type.width > len)
		total = width_format(type, type.width - len + (len ? type.w_precision : 0), len);
	if (ft_strequ(type.result.str, ""))
	{
		if (type.flags.left == 1)
			total = width_format(type, type.width, len);
			return (total);
	}
	if (type.flags.precision == 1)
	{
		while (i < type.w_precision)
		{
			ft_putchar(type.result.str[i]);
			i++;
		}
		total += i;
	}
	else
	{
		ft_putstr(type.result.str);
		total += len;
	}
	if (type.flags.left == 1 && type.width > len)
		total += width_format(type, type.width - len + (len ? type.w_precision : 0), len);
	//print_status(type);
	return (total);
}
