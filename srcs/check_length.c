/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:37:01 by kmckee            #+#    #+#             */
/*   Updated: 2017/11/30 17:40:35 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_len(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (1);
	return (0);
}
t_type	clear_length(t_type type)
{
	type.length.h = 0;
	type.length.hh = 0;
	type.length.l = 0;
	type.length.ll = 0;
	type.length.j = 0;
	type.length.z = 0;
	return (type);
}

t_type	check_length(const char *str, t_type type, int *i)
{	
		type = clear_length(type);
		if (str[*i] == 'h' && str[*i + 1] == 'h')
			type.length.hh = 1;
		else if (str[*i] == 'h' && str[*i + 1] != 'h')
			type.length.h = 1;
		else if (str[*i] == 'l' && str[*i + 1] == 'l')
			type.length.ll = 1;
		else if (str[*i] == 'l' && str[*i + 1] != 'l')
			type.length.l = 1;
		else if (str[*i] == 'z')
			type.length.z = 1;
		else if (str[*i] == 'j')
			type.length.j = 1;
		if (type.length.hh == 1 || type.length.ll == 1)
			*i += 2;
		else if (type.length.h == 1 || type.length.l == 1 || 
				type.length.j == 1 || type.length.z == 1)
			*i += 1;
	while (is_len(str[*i]))
	{		
			if (str[*i] == 'l' && (type.length.hh == 1 || type.length.h == 1))
			{
				type = clear_length(type);
				type.length.l = 1;
			}
			*i += 1;
	}	
	return (type);
}
