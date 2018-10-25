/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_additional.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 21:30:47 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/30 19:47:58 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_x_p(t_params **ts, char **str, long i)
{
	long j;
	long z;

	if ((*ts)->error)
		return ;
	str[0][i + 1] = '\0';
	j = 0;
	i = (i - ft_strlen((*ts)->ostr)) + 1;
	z = i - 1;
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
	i = z;
	while (i >= 0)
		str[0][i--] = '0';
	if ((*ts)->hash == 1)
		str[0][1] = 'x';
}

void	ft_x_0(t_params **ts, char **str, long i)
{
	long j;

	str[0][i + 1] = '\0';
	j = 0;
	i = 0;
	if ((*ts)->hash == 1)
	{
		str[0][i++] = '0';
		str[0][i++] = 'x';
	}
	while ((*ts)->ostr[j])
		str[0][i++] = (*ts)->ostr[j++];
}

void	ft_x_wpd(t_params **ts, char **str, long i)
{
	long j;
	long z;

	if ((*ts)->error)
		return ;
	str[0][i + 1] = '\0';
	j = 0;
	i = (i - ft_strlen(((*ts)->ostr))) + 1;
	z = i - 1;
	while (((*ts)->ostr)[j])
	{
		str[0][i++] = ((*ts)->ostr)[j++];
		(*ts)->p--;
	}
	i = z;
	while ((*ts)->p--)
		str[0][i--] = '0';
	if ((*ts)->hash == 1)
	{
		str[0][i--] = 'x';
		str[0][i--] = '0';
	}
	while (i >= 0)
		str[0][i--] = ' ';
}

void	ft_x_x(char **str, long i)
{
	i = 0;
	while (str[0][i])
	{
		if (str[0][i] > 96 && str[0][i] < 123)
			str[0][i] -= 32;
		i++;
	}
}

void	ft_x_free(char *di_char, char *str, t_params **ts)
{
	if (!(*ts)->error)
	{
		free(di_char);
		free(str);
	}
}
