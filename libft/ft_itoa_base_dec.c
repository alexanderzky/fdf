/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 15:49:12 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/16 18:18:27 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_huge_numb(long value, long size, t_params **ts)
{
	static char		val[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
								'9'};
	unsigned long	uvalue;
	long			i;
	long			j;

	(*ts)->dminus = 1;
	uvalue = (unsigned long)(value * -1);
	size = ft_nbr_lngth(uvalue);
	if (!((*ts)->ostr = (char*)malloc(sizeof(char) * (size + 1))))
	{
		(*ts)->error = 1;
		return ;
	}
	(*ts)->ostr[size] = '\0';
	i = size - 1;
	while (uvalue)
	{
		j = uvalue % 10;
		(*ts)->ostr[i] = val[j];
		uvalue = uvalue / 10;
		i--;
	}
}

void	ft_numb(t_params **ts, long value, long size)
{
	static char	val[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	long		i;
	long		j;

	size = ft_nbr_lngth(value);
	if (!((*ts)->ostr = ft_memalloc(sizeof(char) * (size + 1))))
	{
		(*ts)->error = 1;
		return ;
	}
	(*ts)->ostr[size] = '\0';
	i = size - 1;
	while (value)
	{
		j = value % 10;
		(*ts)->ostr[i] = val[j];
		value = value / 10;
		i--;
	}
}

void	ft_itoa_base_dec(long value, t_params **ts)
{
	long		size;

	size = 0;
	if (value == 0)
	{
		if (!((*ts)->ostr = (char*)malloc(sizeof(char) * (2))))
		{
			(*ts)->error = 1;
			return ;
		}
		(*ts)->ostr[0] = '0';
		(*ts)->ostr[1] = '\0';
	}
	else if (value < 0)
		ft_huge_numb(value, size, ts);
	else
		ft_numb(ts, value, size);
}
