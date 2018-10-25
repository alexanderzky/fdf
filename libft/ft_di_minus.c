/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 17:56:22 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/15 18:01:17 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_di_less(t_params **ts)
{
	(*ts)->plus = -1;
	(*ts)->space = -1;
}

void	ft_di_minus_wsp(t_params **ts, long size, char *str)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[i++] = '+';
	else if ((*ts)->space == 1)
		str[i++] = ' ';
	if ((*ts)->dminus)
	{
		str[0] = '-';
		(*ts)->dminus = 0;
		i++;
	}
	while (ft_strlen((*ts)->ostr) < (*ts)->p)
	{
		str[i++] = '0';
		(*ts)->p--;
	}
	while ((*ts)->ostr[j])
		str[i++] = (*ts)->ostr[j++];
	while (i <= size)
		str[i++] = ' ';
}

void	ft_di_minus_pw(t_params **ts, long size, char *str)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[i++] = '+';
	else if ((*ts)->space == 1)
		str[i++] = ' ';
	while (i <= size)
		str[i++] = '0';
	if ((*ts)->dminus)
	{
		str[0] = '-';
		(*ts)->dminus = 0;
	}
	else if ((*ts)->plus == 1)
		str[0] = '+';
	else if ((*ts)->space == 1)
		str[0] = ' ';
	i = size - ft_sl_d((*ts)->ostr, ts);
	while ((*ts)->ostr[j])
		str[i++] = (*ts)->ostr[j++];
}

void	ft_di_minus_pws(t_params **ts, long size, char *str)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[i++] = '+';
	else if ((*ts)->space == 1)
		str[i++] = ' ';
	if ((*ts)->dminus)
	{
		str[i++] = '-';
		(*ts)->dminus = 0;
	}
	while (j < (*ts)->p - ft_sl_d((*ts)->ostr, ts))
	{
		str[i] = '0';
		i++;
		j++;
	}
	j = 0;
	while ((*ts)->ostr[j])
		str[i++] = (*ts)->ostr[j++];
	while (i <= size)
		str[i++] = ' ';
}

void	ft_di_minus(t_params **ts, long size, char *str)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->plus == 1)
		str[i++] = '+';
	else if ((*ts)->space == 1)
		str[i++] = ' ';
	else if ((*ts)->dminus)
		str[i++] = '-';
	if ((*ts)->w > ft_sl_d((*ts)->ostr, ts) && (*ts)->p <=
			ft_sl_d((*ts)->ostr, ts))
		ft_di_minus_wsp(ts, size, str);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_sl_d((*ts)->ostr, ts)
					|| (*ts)->p > ft_strlen((*ts)->ostr)))
		ft_di_minus_pw(ts, size, str);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_sl_d((*ts)->ostr, ts))
		ft_di_minus_pws(ts, size, str);
	else
		while ((*ts)->ostr[j])
			str[i++] = (*ts)->ostr[j++];
}
