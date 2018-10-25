/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_additional.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 14:32:45 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 14:25:41 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_u_size_forbuffer_add(t_params **temp)
{
	long size;

	size = ft_strlen((*temp)->ostr);
	if ((*temp)->ostr[0] == '0' && (*temp)->p == 0)
	{
		(*temp)->ostr[0] = '\0';
		size = 0;
	}
	if ((*temp)->w > size && (*temp)->ostr[0] == '0' && (*temp)->p == 0)
	{
		size = (*temp)->w;
	}
	else if ((*temp)->p > size || (*temp)->w > size)
	{
		if ((*temp)->w >= (*temp)->p)
			size = (*temp)->w;
		else
			size = (*temp)->p;
	}
	if ((*temp)->w == (ft_strlen((*temp)->ostr) && (*temp)->zero == 1))
		size++;
	return (size);
}

void	ft_u_minus_wps(t_params **temp, char **str, long size)
{
	long j;
	long i;

	i = 0;
	j = 0;
	while (j < (*temp)->p - ft_strlen((*temp)->ostr))
	{
		str[0][i] = '0';
		i++;
		j++;
	}
	j = 0;
	while ((*temp)->ostr[j])
		str[0][i++] = (*temp)->ostr[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_u_minus(t_params **ts, char **str, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->w > ft_strlen((*ts)->ostr) && (*ts)->p <= ft_strlen((*ts)->ostr))
	{
		while ((*ts)->ostr[j])
			str[0][i++] = (*ts)->ostr[j++];
		while (i < size)
			str[0][i++] = ' ';
	}
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_strlen((*ts)->ostr)))
	{
		while (i < size)
			str[0][i++] = '0';
		i = size - ft_strlen((*ts)->ostr);
		while ((*ts)->ostr[j])
			str[0][i++] = (*ts)->ostr[j++];
	}
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_strlen((*ts)->ostr))
		ft_u_minus_wps(ts, str, size);
	else
		while ((*ts)->ostr[j])
			str[0][i++] = (*ts)->ostr[j++];
}
