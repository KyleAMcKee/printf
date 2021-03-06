/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:45:43 by kmckee            #+#    #+#             */
/*   Updated: 2017/12/07 14:51:21 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_format(t_type type, va_list ap)
{
	type = arg_conversion(type, ap);
	*type.res.intp = type.ret;
	return (0);
}
