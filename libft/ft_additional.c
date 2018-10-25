/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_additional.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:29:35 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/15 17:16:31 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_format_len(const char **format)
{
	size_t i;

	i = 0;
	while (format[0][i] && format[0][i] != '%')
		i++;
	return (i);
}

void	ft_di_wps(t_params **ts, long i, long j, char *str)
{
	if ((*ts)->dminus)
	{
		(*ts)->dminus = 0;
		(*ts)->minus = 1;
	}
	i = (i - ft_sl_d((*ts)->ostr, ts)) + 1;
	while ((*ts)->ostr[j])
	{
		str[i++] = (*ts)->ostr[j++];
		(*ts)->p--;
	}
	i -= ((*ts)->dminus) ? ft_sl_d((*ts)->ostr, ts) :
		ft_strlen((*ts)->ostr) + 1;
	while ((*ts)->p--)
		str[i--] = '0';
	if ((*ts)->plus == 1)
		str[i--] = '+';
	else if ((*ts)->space == 1)
		str[i--] = ' ';
	else if ((*ts)->minus == 1)
		str[i--] = '-';
	while (i >= 0)
		str[i--] = ' ';
}

void	ft_di_else(t_params **ts, char *str)
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
		str[i++] = '-';
	while ((*ts)->ostr[j])
		str[i++] = (*ts)->ostr[j++];
}

long	ft_p_size(t_params **temp)
{
	long size;

	if ((*temp)->ostr[0] == '0' && (*temp)->p == 0)
		size = 0;
	else
		size = ft_strlen((*temp)->ostr);
	if ((*temp)->p > size || (*temp)->w > size)
	{
		if ((*temp)->w > (*temp)->p)
			size = (*temp)->w;
		else
			size = (*temp)->p;
	}
	if ((*temp)->w == ft_strlen((*temp)->ostr) + 1)
		size++;
	else if ((ft_strlen((*temp)->ostr) + 2 > size) || (*temp)->p == size)
		size += 2;
	return (size);
}
