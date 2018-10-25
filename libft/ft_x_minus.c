/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 21:33:36 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/30 19:47:58 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_x_minus_hash(char **str, long i)
{
	str[0][i++] = '0';
	str[0][i++] = 'x';
	return (i);
}

void	ft_x_minus_wdp(t_params **ts, char **str, long i, long size)
{
	long j;

	j = 0;
	if (!((*ts)->ostr[0] == '0' && (*ts)->p == 0))
		while ((*ts)->ostr[j])
			str[0][i++] = (*ts)->ostr[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_x_minus_p(t_params **ts, char **str, long i, long size)
{
	long j;

	j = 0;
	while (i < size)
		str[0][i++] = '0';
	i = size - ft_strlen((*ts)->ostr);
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
}

void	ft_x_minus_wpd(t_params **ts, char **str, long i, long size)
{
	long j;

	j = 0;
	while (j < (*ts)->p - ft_strlen((*ts)->ostr))
	{
		str[0][i] = '0';
		i++;
		(*ts)->p--;
	}
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_x_minus(t_params **ts, char **str, char *di_char, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	str[0][size] = '\0';
	if ((*ts)->hash == 1)
		i = ft_x_minus_hash(str, i);
	if ((*ts)->w > (int)ft_strlen(di_char) &&
			(*ts)->p <= (int)ft_strlen(di_char))
		ft_x_minus_wdp(ts, str, i, size);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > (int)ft_strlen(di_char)))
		ft_x_minus_p(ts, str, i, size);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > (int)ft_strlen(di_char))
		ft_x_minus_wpd(ts, str, i, size);
	else if ((*ts)->ostr[0] == '0' && (*ts)->p == 0)
		str[0][0] = '\0';
	else
		while ((*ts)->ostr[j])
			str[0][i++] = (*ts)->ostr[j++];
}
