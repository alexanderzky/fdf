/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_additional.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 18:10:05 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/15 18:10:03 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_di_zero(t_params **ts, long i, char *str)
{
	if ((*ts)->dminus)
	{
		while (i > 0)
		{
			str[i--] = '0';
			(*ts)->w--;
		}
		str[i] = '-';
		(*ts)->w--;
	}
	else if ((*ts)->plus == 1 || (*ts)->space == 1)
	{
		while (i > 0)
			str[i--] = '0';
	}
	else
		while (i >= 0)
			str[i--] = '0';
	return (i);
}

long	ft_di_putchar(t_params **ts, long i, char *str)
{
	if ((*ts)->plus == 1 && i >= 0)
	{
		str[i--] = '+';
		(*ts)->w--;
	}
	if ((*ts)->dminus && i >= 0)
	{
		str[i--] = '-';
		(*ts)->w--;
		(*ts)->dminus = 0;
	}
	if ((*ts)->space == 1 && i >= 0)
	{
		str[i--] = ' ';
		(*ts)->w--;
	}
	return (i);
}

long	ft_di_ostr_copy(t_params **ts, long i, char *str)
{
	long j;

	j = ft_strlen((*ts)->ostr) - 1;
	while (j >= 0)
	{
		str[i] = (*ts)->ostr[j];
		i--;
		j--;
		(*ts)->w--;
		(*ts)->p--;
	}
	return (i);
}

void	ft_di_wsp(t_params **ts, long i, char *str)
{
	i = ft_di_ostr_copy(ts, i, str);
	if ((*ts)->zero == 1)
		i = ft_di_zero(ts, i, str);
	else if ((*ts)->p > 0)
	{
		str[i--] = '0';
		(*ts)->p--;
		(*ts)->w--;
	}
	i = ft_di_putchar(ts, i, str);
	while ((*ts)->w > 0 && i >= 0)
	{
		str[i--] = ' ';
		(*ts)->w--;
	}
	if ((*ts)->dminus)
		str[0] = '-';
}

void	ft_di_p(t_params **ts, long i, char *str)
{
	long j;

	j = 0;
	i = (i - ft_strlen((*ts)->ostr)) + 1;
	while ((*ts)->ostr[j])
		str[i++] = (*ts)->ostr[j++];
	i -= ((*ts)->dminus) ? ft_sl_d((*ts)->ostr, ts) :
		ft_strlen((*ts)->ostr) + 1;
	while (i > 0)
		str[i--] = '0';
	if ((*ts)->plus == 1)
		str[i] = '+';
	else if ((*ts)->space == 1)
		str[i] = ' ';
	else if ((*ts)->dminus)
		str[i] = '-';
	else
		str[i] = '0';
}
