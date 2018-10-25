/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:39:25 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 20:42:35 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_buffer_wc2(t_params **temp, wchar_t c)
{
	if (c > 2047 && c < 65536)
	{
		ft_putchar((c >> 12) + 224);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
		(*temp)->counter += 3;
	}
	else if (c > 65535 && c < 2097152)
	{
		ft_putchar((c >> 18) + 240);
		ft_putchar(((c >> 12) & 63) + 128);
		ft_putchar(((c >> 6) & 63) + 128);
		ft_putchar((c & 63) + 128);
		(*temp)->counter += 4;
	}
}

void	ft_buffer_wc(t_params **temp, wchar_t c)
{
	if (c < 128)
	{
		ft_putchar(c);
		(*temp)->counter += 1;
	}
	else if (c > 127 && c < 2048)
	{
		ft_putchar((c >> 6) + 192);
		ft_putchar((c & 63) + 128);
		(*temp)->counter += 2;
	}
	else
		ft_buffer_wc2(temp, c);
}

void	ft_wc_minus(t_params **temp, wchar_t **str, wchar_t c, long size)
{
	long i;

	i = 0;
	if ((*temp)->w > 1)
	{
		str[0][i++] = c;
		while (i < size)
			str[0][i++] = ' ';
	}
	else
		str[0][i] = c;
}

void	ft_wc_width(t_params **temp, wchar_t **str, wchar_t c, long size)
{
	long i;

	i = 0;
	if ((*temp)->zero == 1)
		while (i < size - 1)
			str[0][i++] = '0';
	else
		while (i < size - 1)
			str[0][i++] = ' ';
	str[0][i] = c;
}

void	ft_buffer_add_wc(t_params **ts, wchar_t c)
{
	wchar_t	*str;
	long	size;
	int		i;

	size = 1;
	if ((*ts)->w > 0 && (*ts)->p > 0)
		size = (*ts)->w;
	if (!(str = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1))))
		(*ts)->error = 1;
	if (!(*ts)->error)
		str[size] = '\0';
	i = 0;
	if ((*ts)->minus == 1 && !(*ts)->error)
		ft_wc_minus(ts, &str, c, size);
	else if ((*ts)->w > 1 && !(*ts)->error)
		ft_wc_width(ts, &str, c, size);
	else if (!(*ts)->error)
		str[i] = c;
	i = 0;
	while (size-- && !(*ts)->error)
		ft_buffer_wc(ts, str[i++]);
	if (!(*ts)->error)
		free(str);
}
