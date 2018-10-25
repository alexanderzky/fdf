/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ws_minus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:19:56 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 20:07:42 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ws_minus_wsp(wchar_t **str, wchar_t *s, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	while (i < ft_strsimplelen(s))
		str[0][i++] = s[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_ws_minus_wps(t_params **ts, wchar_t **str, wchar_t *s, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	while (i < size - ft_precstrlen(ts, s))
		str[0][i++] = s[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_ws_minus_else(t_params **ts, wchar_t **str, wchar_t *s, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	while (i < ft_precstrlen(ts, s))
		str[0][i++] = s[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_ws_minus(t_params **ts, wchar_t **str, wchar_t *s, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if (ft_strsimplelen(s) == 0)
		while (i < size)
			str[0][i++] = ' ';
	else if ((size > (*ts)->w && (*ts)->p < 0))
		while (i < size)
			str[0][i++] = s[j++];
	else if ((((*ts)->w > ft_strsimplelen(s) && ((*ts)->p < 0 ||
			(*ts)->p > ft_strwlen(s)))))
		ft_ws_minus_wsp(str, s, size);
	else if ((*ts)->p == 0)
		while (i < size)
			str[0][i++] = ' ';
	else if ((((*ts)->w > ft_strsimplelen(s) && (*ts)->p < ft_strwlen(s))))
		ft_ws_minus_wps(ts, str, s, size);
	else if ((((*ts)->p < ft_strwlen(s))))
		ft_ws_minus_else(ts, str, s, size);
}
