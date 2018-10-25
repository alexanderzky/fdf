/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:56:32 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 22:20:45 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_u_wsp(t_params **temp, char **str, long i)
{
	long j;

	j = ft_strlen((*temp)->ostr) - 1;
	while (j >= 0)
	{
		str[0][i] = (*temp)->ostr[j];
		i--;
		j--;
		(*temp)->w--;
	}
	if ((*temp)->zero == 1)
		while (i >= 0)
			str[0][i--] = '0';
	while ((*temp)->w > 0 && i >= 0)
	{
		str[0][i--] = ' ';
		(*temp)->w--;
	}
}

void	ft_u_psw(t_params **temp, char **str, long i)
{
	long j;

	if ((*temp)->error)
		return ;
	j = 0;
	i = (i - ft_strlen((*temp)->ostr)) + 1;
	while ((*temp)->ostr[j])
		str[0][i++] = (*temp)->ostr[j++];
	i -= ft_strlen((*temp)->ostr) + 1;
	while (i > 0)
		str[0][i--] = '0';
	str[0][i] = '0';
}

void	ft_u_wps(t_params **temp, char **str, long i)
{
	long j;

	if ((*temp)->error)
		return ;
	j = 0;
	i = (i - ft_strlen((*temp)->ostr)) + 1;
	while ((*temp)->ostr[j])
	{
		str[0][i++] = (*temp)->ostr[j++];
		(*temp)->p--;
	}
	i -= ft_strlen((*temp)->ostr) + 1;
	while ((*temp)->p--)
		str[0][i--] = '0';
	while (i >= 0)
		str[0][i--] = ' ';
}

void	ft_u_else(t_params **temp, char **str)
{
	long j;
	long i;

	j = 0;
	i = 0;
	while ((*temp)->ostr[j])
		str[0][i++] = (*temp)->ostr[j++];
}

void	ft_buffer_add_u(t_params **ts, char *ostr)
{
	char *str;
	long size;
	long i;

	(*ts)->ostr = ostr;
	size = ft_u_size_forbuffer_add(ts);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		(*ts)->error = 1;
	if (!(*ts)->error)
		str[size] = '\0';
	i = size - 1;
	if ((*ts)->minus == 1 && !(*ts)->error)
		ft_u_minus(ts, &str, size);
	else if ((*ts)->w > ft_strlen((*ts)->ostr) &&
			(*ts)->p <= ft_strlen((*ts)->ostr) && !(*ts)->error)
		ft_u_wsp(ts, &str, i);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_strlen((*ts)->ostr)))
		ft_u_psw(ts, &str, i);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_strlen((*ts)->ostr))
		ft_u_wps(ts, &str, i);
	else if (!(*ts)->error)
		ft_u_else(ts, &str);
	if (!(*ts)->error)
		(*ts)->counter += write(1, str, ft_strlen(str));
	ft_x_free(str, ostr, ts);
}
