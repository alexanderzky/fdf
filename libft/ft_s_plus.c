/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:58:41 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 20:42:35 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_s_plus_s0(t_params **ts, char **str, long size)
{
	long i;

	i = 0;
	if ((*ts)->zero == 1)
		while (i < size)
			str[0][i++] = '0';
	else
		while (i < size)
			str[0][i++] = ' ';
	return (i);
}

long	ft_s_plus_0(t_params **ts, char **str, long size)
{
	long i;

	i = 0;
	if ((*ts)->freeme)
		while (i < size - (*ts)->p)
			str[0][i++] = '0';
	else
		while (i < size)
			str[0][i++] = '0';
	return (i);
}

long	ft_s_plus_0s(t_params **ts, char **str, char *s, long size)
{
	long i;

	i = 0;
	if ((*ts)->freeme)
		while (i < size - (*ts)->p)
			str[0][i++] = '0';
	else
		while (i < size - (*ts)->p && i < size - ft_strlen(s))
			str[0][i++] = '0';
	return (i);
}

long	ft_s_plus_w(t_params **ts, char **str, char *s, long size)
{
	long i;

	i = 0;
	if ((*ts)->zero == 1)
		while (i < size - ft_strlen(s))
			str[0][i++] = '0';
	if ((*ts)->p > -1 && (*ts)->p < ft_strlen(s))
		while (i < size - (*ts)->p)
			str[0][i++] = ' ';
	else
		while (i < size - ft_strlen(s))
			str[0][i++] = ' ';
	return (i);
}

void	ft_s_plus(t_params **ts, char **str, char *s, long size)
{
	long i;
	long j;

	i = 0;
	j = 0;
	if (ft_strlen(s) == 0)
		i = ft_s_plus_s0(ts, str, size);
	else if ((*ts)->zero == 1 && (*ts)->w > (*ts)->p && (*ts)->p == 0)
		i = ft_s_plus_0(ts, str, size);
	else if ((*ts)->zero == 1 && (*ts)->w > (*ts)->p && (*ts)->p < ft_strlen(s))
		i = ft_s_plus_0s(ts, str, s, size);
	else if ((*ts)->w == size)
		i = ft_s_plus_w(ts, str, s, size);
	while (i < size)
		str[0][i++] = s[j++];
}
