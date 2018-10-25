/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:30:52 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 22:23:47 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_size_forbuffer_add(t_params **temp)
{
	long size;

	if ((*temp)->ostr[0] == '0' && (*temp)->p == 0 && (*temp)->hash == 1)
		size = 1;
	else if ((*temp)->ostr[0] == '0' && (*temp)->p == 0)
		size = 0;
	else
		size = ft_strlen((*temp)->ostr);
	if ((*temp)->p > size || (*temp)->w > size)
	{
		if ((*temp)->w > (*temp)->p)
			size = (*temp)->w;
		else
			size = (*temp)->p;
	}
	if ((*temp)->hash == 1 && size == (ft_strlen((*temp)->ostr)) &&
			(*temp)->ostr[0] != '0')
		size++;
	return (size);
}

void	ft_o_psw(t_params **temp, char **str, long i)
{
	long j;

	if ((*temp)->error)
		return ;
	j = 0;
	i = (i - ft_strlen((*temp)->ostr)) + 1;
	while ((*temp)->ostr[j])
		str[0][i++] = (*temp)->ostr[j++];
	i -= ft_strlen((*temp)->ostr) + 1;
	while (i >= 0)
		str[0][i--] = '0';
}

void	ft_o_wps(t_params **temp, char **str, long i)
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

void	ft_o_else(t_params **temp, char **str)
{
	long j;
	long i;

	if ((*temp)->error)
		return ;
	j = 0;
	i = 0;
	if ((*temp)->hash == 1 && (*temp)->ostr[0] != '0')
		str[0][i++] = '0';
	while ((*temp)->ostr[j])
		str[0][i++] = (*temp)->ostr[j++];
}

void	ft_buffer_add_o(t_params **ts, char *ostr)
{
	char *str;
	long size;

	(*ts)->ostr = ostr;
	size = ft_size_forbuffer_add(ts);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		(*ts)->error = 1;
	if (!(*ts)->error)
		str[size] = '\0';
	if ((*ts)->minus == 1 && !(*ts)->error)
		ft_o_minus(ts, &str, size);
	else if ((*ts)->w > ft_strlen((*ts)->ostr) &&
			(*ts)->p <= ft_strlen((*ts)->ostr) && !(*ts)->error)
		ft_o_wsp(ts, &str, size - 1, 0);
	else if ((*ts)->p >= (*ts)->w && ((*ts)->p > ft_strlen(ostr)))
		ft_o_psw(ts, &str, size - 1);
	else if ((*ts)->w > (*ts)->p && (*ts)->p > ft_strlen((*ts)->ostr))
		ft_o_wps(ts, &str, size - 1);
	else if ((*ts)->ostr[0] == '0' && (*ts)->p == 0 && (*ts)->hash != 1)
		str[0] = '\0';
	else
		ft_o_else(ts, &str);
	if (!(*ts)->error)
		(*ts)->counter += write(1, str, ft_strlen(str));
	ft_x_free(str, ostr, ts);
}
