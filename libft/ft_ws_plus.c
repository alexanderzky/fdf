/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ws_plus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:45:47 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 20:07:42 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ws_plus_wl(t_params **ts, wchar_t **str, long size)
{
	long i;

	i = 0;
	if ((*ts)->zero == 1)
		while (i < size)
			str[0][i++] = '0';
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_ws_plus_ws(t_params **ts, wchar_t **str, wchar_t *s, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->zero == 1)
		while (i < size - ft_strsimplelen(s))
			str[0][i++] = '0';
	while (i < size - ft_strsimplelen(s))
		str[0][i++] = ' ';
	while (i < size)
		str[0][i++] = s[j++];
}

void	ft_ws_plus_wsp(t_params **ts, wchar_t **str, wchar_t *s, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->zero == 1)
		while (i < size - ft_precstrlen(ts, s))
			str[0][i++] = '0';
	while (i < size - ft_precstrlen(ts, s))
		str[0][i++] = ' ';
	while (i < size)
		str[0][i++] = s[j++];
}

void	ft_ws_plus_swp(t_params **ts, wchar_t **str, wchar_t *s, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((*ts)->zero == 1)
	{
		if ((*ts)->p == 0)
			while (i < size)
				str[0][i++] = '0';
		else
			while (i < size - (*ts)->p)
				str[0][i++] = '0';
	}
	while (i < (*ts)->w - (*ts)->p)
		str[0][i++] = ' ';
	while (i < size)
		str[0][i++] = s[j++];
}

void	ft_ws_plus(t_params **ts, wchar_t **str, wchar_t *s, long size)
{
	long i;
	long j;

	j = 0;
	i = 0;
	if ((((*ts)->w >= ft_strsimplelen(s) && (*ts)->p == 0)))
		ft_ws_plus_wl(ts, str, size);
	else if ((size > (*ts)->w && (*ts)->p < 0))
		while (i < size)
			str[0][i++] = s[j++];
	else if ((((*ts)->w > ft_strsimplelen(s) && ((*ts)->p < 0 ||
			(*ts)->p >= ft_strwlen(s)))))
		ft_ws_plus_ws(ts, str, s, size);
	else if ((((*ts)->w >= ft_strsimplelen(s) && (*ts)->p < ft_strwlen(s))))
		ft_ws_plus_wsp(ts, str, s, size);
	else if ((((*ts)->w < ft_strsimplelen(s) && (*ts)->p < ft_strwlen(s))))
		ft_ws_plus_swp(ts, str, s, size);
	else if (ft_strsimplelen(s) == 0)
		ft_ws_plus_0(ts, str, size);
}
