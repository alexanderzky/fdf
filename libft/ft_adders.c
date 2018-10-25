/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:48:56 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 15:13:48 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_flag_add(t_params **ts, const char **format)
{
	if (**format == '-')
		(*ts)->minus = 1;
	else if (**format == '+')
		(*ts)->plus = 1;
	else if (**format == ' ')
		(*ts)->space = 1;
	else if (**format == '#')
		(*ts)->hash = 1;
	else if (**format == '0')
		(*ts)->zero = 1;
}

void		ft_width_add(t_params **ts, const char **format, va_list vl)
{
	int len;
	int wildcard;

	if (**format == 42)
	{
		wildcard = va_arg(vl, int);
		if (wildcard < 0)
		{
			(*ts)->minus = 1;
			wildcard *= -1;
		}
		(*ts)->w = wildcard;
	}
	else
	{
		(*ts)->w = ft_atoi(*format);
		len = ft_nbr_lngth(ft_atoi(*format));
		*format += len - 1;
	}
}

void		ft_prec_add(t_params **temp, const char **format, va_list vl)
{
	int wildcard;

	if (*(*format + 1) > 47 && *(*format + 1) < 58)
	{
		*format += 1;
		(*temp)->p = ft_atoi(*format);
		while (*(*format) > 47 && *(*format) < 58 && (*(*format + 1) > 47
													&& *(*format + 1) < 58))
			*format += 1;
	}
	else if (*(*format + 1) == 42)
	{
		wildcard = va_arg(vl, int);
		if (wildcard < 0)
			(*temp)->p = -1;
		else
			(*temp)->p = wildcard;
		*format += 1;
	}
	else
		(*temp)->p = 0;
}

void		ft_length_add(t_params **ts, const char **format)
{
	if (**format == 'h' && (*ts)->length < 2)
	{
		if ((*ts)->length == -1)
			(*ts)->length = 1;
		else if ((*ts)->length == 0)
			(*ts)->length = 1;
		else if ((*ts)->length == 1)
			(*ts)->length = 0;
	}
	else if (**format == 'l' && (*(*format + 1)) == 'l' && (*ts)->length < 3)
		(*ts)->length = 3;
	else if (**format == 'l' && (*ts)->length < 2)
		(*ts)->length = 2;
	else if (**format == 'j' && (*ts)->length < 5)
		(*ts)->length = 5;
	else if (**format == 'z' && (*ts)->length < 4)
		(*ts)->length = 4;
	if ((*ts)->length == 3)
		(*format)++;
}

void		ft_type_add(t_params **ts, const char **format)
{
	if (**format == 'D' || **format == 'O' || **format == 'U' ||
		**format == 'C' || **format == 'S' || **format == 'B')
	{
		(*ts)->length = 2;
		(*ts)->type = (**format + 32);
	}
	else if (**format == 'X')
	{
		(*ts)->type = 'x';
		(*ts)->x = 1;
	}
	else
		(*ts)->type = **format;
}
