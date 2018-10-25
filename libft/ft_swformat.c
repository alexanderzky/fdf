/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:05:33 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/15 19:58:20 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ws_plus_0(t_params **ts, wchar_t **str, long size)
{
	long i;

	i = 0;
	if ((*ts)->zero == 1)
		while (i < size)
			str[0][i++] = '0';
	else
		while (i < size)
			str[0][i++] = ' ';
}

long	ft_ws_size(t_params **ts, wchar_t *s)
{
	long size;

	if ((*ts)->error)
		return (0);
	size = ft_strsimplelen(s);
	if ((*ts)->p == 0)
	{
		if ((*ts)->w > 0)
			size = (*ts)->w;
		else
			size = 0;
	}
	else if ((*ts)->w > ft_strwlen(s))
		size = (*ts)->w - ft_precwidstrlen(ts, s) + ft_precstrlen(ts, s);
	else if ((*ts)->p > 0 && (*ts)->p < ft_strwlen(s))
	{
		if ((*ts)->w > ft_precwidstrlen(ts, s))
			size = (*ts)->w - ft_precwidstrlen(ts, s) + ft_precstrlen(ts, s);
		else
			size = ft_precstrlen(ts, s);
	}
	return (size);
}

void	ft_ws_0(t_params **ts, wchar_t **s)
{
	(*ts)->freeme = 1;
	if (!(s[0] = malloc(sizeof(wchar_t) * 7)))
	{
		(*ts)->error = 1;
		return ;
	}
	s[0][0] = '(';
	s[0][1] = 'n';
	s[0][2] = 'u';
	s[0][3] = 'l';
	s[0][4] = 'l';
	s[0][5] = ')';
	s[0][6] = '\0';
}

void	ft_buffer_add_ws(t_params **ts, wchar_t *s)
{
	wchar_t	*str;
	long	size;
	int		i;

	if (!s || s[0] == '0')
		ft_ws_0(ts, &s);
	if (!(size = ft_ws_size(ts, s)))
		return ;
	if (!(str = malloc(sizeof(wchar_t) * (size + 1))))
		(*ts)->error = 1;
	if (!(*ts)->error)
		str[size] = '\0';
	if ((*ts)->minus == 1 && !(*ts)->error)
		ft_ws_minus(ts, &str, s, size);
	else if (!(*ts)->error)
		ft_ws_plus(ts, &str, s, size);
	i = 0;
	while (str[i] && !(*ts)->error)
		ft_buffer_wc(ts, str[i++]);
	if (!(*ts)->error)
		free(str);
	if ((*ts)->freeme == 1 && !(*ts)->error)
		free(s);
}
