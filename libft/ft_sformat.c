/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:25:56 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/15 19:57:29 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_s_size(t_params **ts, char *s)
{
	long size;

	if (!s && (*ts)->p < 0)
		size = 6;
	else if (!s && (*ts)->p > -1)
		size = (*ts)->p;
	else if (s[0] == '0' && (*ts)->p < 0)
		size = 6;
	else if (s[0] == '0' && (*ts)->p > -1)
		size = (*ts)->p;
	else
		size = ft_strlen(s);
	if ((*ts)->w > size)
		size = (*ts)->w;
	else if ((*ts)->w <= (*ts)->p && (*ts)->p > -1 && (*ts)->p < size)
		size = (*ts)->p;
	else if ((*ts)->w > 0 && (*ts)->w < size && (*ts)->p > -1 &&
			(*ts)->p < size)
		size = (*ts)->w;
	return (size);
}

void	ft_s_0(t_params **ts, char **s)
{
	(*ts)->freeme = 1;
	if (!(s[0] = malloc(sizeof(char) * 7)))
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

void	ft_s_minus(t_params **ts, char **str, char *s, long size)
{
	int		i;
	long	j;

	i = 0;
	j = 0;
	if ((*ts)->p > -1 && (*ts)->p < ft_strlen(s))
		while ((*ts)->p--)
			str[0][i++] = s[j++];
	else
		while (s[j])
			str[0][i++] = s[j++];
	while (i < size)
		str[0][i++] = ' ';
}

void	ft_buffer_add_s(t_params **ts, char *s)
{
	char	*str;
	long	size;
	int		i;

	size = ft_s_size(ts, s);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		(*ts)->error = 1;
	if (!(*ts)->error)
		str[size] = '\0';
	if ((!s || s[0] == '0') && !(*ts)->error)
		ft_s_0(ts, &s);
	if ((*ts)->minus == 1 && !(*ts)->error)
		ft_s_minus(ts, &str, s, size);
	else if (!(*ts)->error)
		ft_s_plus(ts, &str, s, size);
	i = 0;
	while (size-- && !(*ts)->error)
		ft_buffer_wc(ts, str[i++]);
	if (!(*ts)->error)
		free(str);
	if ((*ts)->freeme == 1 && !(*ts)->error)
		free(s);
}
