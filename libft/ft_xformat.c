/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 17:55:26 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/30 19:47:58 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_x_size_0(t_params **ts)
{
	long size;

	size = 0;
	(*ts)->hash = -1;
	return (size);
}

long	ft_x_size(t_params **ts, char *di_char)
{
	long size;

	if (di_char[0] == '0' && (*ts)->p == 0)
		size = ft_x_size_0(ts);
	else if (di_char[0] == '0')
	{
		size = 1;
		(*ts)->hash = -1;
	}
	else
		size = (int)ft_strlen(di_char);
	if ((*ts)->p > size || (*ts)->w > size)
	{
		if ((*ts)->w > (*ts)->p)
			size = (*ts)->w;
		else
			size = (*ts)->p;
	}
	if ((*ts)->hash == 1 && (size == (int)ft_strlen(di_char) ||
			((*ts)->p > (*ts)->w && (*ts)->p > ft_strlen(di_char))))
		size += 2;
	else if ((*ts)->hash == 1 && (*ts)->p + 1 == size)
		size++;
	return (size);
}

long	ft_x_00(t_params **ts, char **str, long i, long j)
{
	while (j >= 0)
	{
		str[0][i] = (*ts)->ostr[j];
		i--;
		j--;
		(*ts)->w--;
	}
	return (i);
}

void	ft_x_wdp(t_params **ts, char **str, long i)
{
	long j;

	if ((*ts)->error)
		return ;
	str[0][i + 1] = '\0';
	j = ft_strlen((*ts)->ostr) - 1;
	if (!((*ts)->ostr[0] == '0' && (*ts)->p == 0))
		i = ft_x_00(ts, str, i, j);
	if ((*ts)->zero == 1 && (*ts)->hash == 1)
		while (i > 1)
			str[0][i--] = '0';
	if ((*ts)->zero == 1 && (*ts)->hash == -1)
		while (i > -1)
			str[0][i--] = '0';
	if ((*ts)->hash == 1)
	{
		str[0][i--] = 'x';
		str[0][i--] = '0';
		(*ts)->w--;
	}
	while ((*ts)->w > 0 && i >= 0)
	{
		str[0][i--] = ' ';
		(*ts)->w--;
	}
}

void	ft_buffer_add_xx(t_params **ts, char *di_char)
{
	char *str;
	long size;

	size = ft_x_size(ts, di_char);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		(*ts)->error = 1;
	(*ts)->ostr = di_char;
	if ((*ts)->minus == 1 && !(*ts)->error)
		ft_x_minus(ts, &str, di_char, size);
	else if ((*ts)->w > (int)ft_strlen(di_char) &&
			(*ts)->p <= (int)ft_strlen(di_char) && !(*ts)->error)
		ft_x_wdp(ts, &str, size - 1);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > (int)ft_strlen(di_char)))
		ft_x_p(ts, &str, size - 1);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > (int)ft_strlen(di_char))
		ft_x_wpd(ts, &str, size - 1);
	else if (di_char[0] == '0' && (*ts)->p == 0 && !(*ts)->error)
		str[0] = '\0';
	else if (!(*ts)->error)
		ft_x_0(ts, &str, size - 1);
	if ((*ts)->x > 0 && !(*ts)->error)
		ft_x_x(&str, size - 1);
	if (!(*ts)->error)
		(*ts)->counter += write(1, str, (size_t)ft_strlen(str));
	ft_x_free(di_char, str, ts);
}
