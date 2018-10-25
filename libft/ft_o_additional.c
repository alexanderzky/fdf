/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_additional.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:37:20 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 17:08:15 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_0_wsp(t_params **temp, char **str, long size, long i)
{
	long j;

	j = 0;
	if ((*temp)->ostr[0] != '0')
		while ((*temp)->ostr[j])
			str[0][i++] = (*temp)->ostr[j++];
	else if ((*temp)->w > 0 && (*temp)->ostr[0] == '0' && (*temp)->hash != 1)
		str[0][i++] = '0';
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_0_wps(t_params **temp, char **str, long size, long i)
{
	long j;

	j = 0;
	while (j < (*temp)->p - ft_strlen((*temp)->ostr))
	{
		str[0][i] = '0';
		i++;
		(*temp)->p--;
	}
	j = 0;
	while ((*temp)->ostr[j])
		str[0][i++] = (*temp)->ostr[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_o_ps(t_params **temp, char **str, long size, long i)
{
	long j;

	j = 0;
	while (i < size)
		str[0][i++] = '0';
	i = size - ft_strlen((*temp)->ostr);
	while ((*temp)->ostr[j])
		str[0][i++] = (*temp)->ostr[j++];
}

void	ft_o_minus(t_params **ts, char **str, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->hash == 1 && (*ts)->p <= ft_strlen((*ts)->ostr))
		str[0][i++] = '0';
	if ((*ts)->w > ft_strlen((*ts)->ostr) && (*ts)->p <= ft_strlen((*ts)->ostr))
		ft_0_wsp(ts, str, size, i);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_strlen((*ts)->ostr)))
		ft_o_ps(ts, str, size, i);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_strlen((*ts)->ostr))
		ft_0_wps(ts, str, size, i);
	else if ((*ts)->ostr[0] == '0' && (*ts)->p == 0 && (*ts)->hash != 1)
		str[0][0] = '\0';
	else if ((*ts)->ostr[0] == '0' && (*ts)->p == 0 && (*ts)->hash == 1)
		str[0][i] = '\0';
	else
		while ((*ts)->ostr[j] && i < size)
			str[0][i++] = (*ts)->ostr[j++];
}

void	ft_o_wsp(t_params **temp, char **str, long i, long j)
{
	j = ft_strlen((*temp)->ostr) - 1;
	if ((*temp)->ostr[0] != '0')
	{
		while (j >= 0)
		{
			str[0][i] = (*temp)->ostr[j];
			i-- && j--;
			(*temp)->w--;
		}
	}
	if ((*temp)->zero == 1)
		while (i >= 0)
			str[0][i--] = '0';
	else if ((*temp)->hash == 1)
	{
		str[0][i--] = '0';
		(*temp)->w--;
	}
	else if ((*temp)->w > 0 && (*temp)->ostr[0] == '0' && (*temp)->p != 0)
		str[0][i--] = '0';
	while ((*temp)->w > 0 && i >= 0)
	{
		str[0][i--] = ' ';
		(*temp)->w--;
	}
}
