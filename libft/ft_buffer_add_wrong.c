/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_add_wrong.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 21:05:31 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 22:04:48 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_wrong_else(t_params **temp, char **str, long size, const char **s)
{
	long i;

	i = 0;
	if ((*temp)->zero == 1)
	{
		while (i < size - 1)
			str[0][i++] = '0';
	}
	else if ((*temp)->w == size)
		while (i < size - 1)
			str[0][i++] = ' ';
	while (i < size)
		str[0][i++] = *s[0];
}

void	ft_buffer_add_wrong(t_params **ts, const char **s)
{
	char	*str;
	long	size;
	int		i;

	(*ts)->skip = 1;
	size = 1;
	if ((*ts)->w > size)
		size = (*ts)->w;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		(*ts)->error = 1;
	str[size] = '\0';
	i = 0;
	if ((*ts)->minus == 1)
	{
		str[i++] = *s[0];
		while (i < size)
			str[i++] = ' ';
	}
	else
		ft_wrong_else(ts, &str, size, s);
	if (!(*ts)->error)
		(*ts)->counter += write(1, str, ft_strlen(str));
	if (!(*ts)->error)
		free(str);
}
