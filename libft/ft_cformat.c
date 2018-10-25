/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:28:04 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 22:20:45 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_c_minus(t_params **temp, char **str, char c, long size)
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

void	ft_c_width(t_params **temp, char **str, char c, long size)
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

void	ft_buffer_add_c(t_params **ts, unsigned char c)
{
	char	*str;
	long	size;
	int		i;

	size = 1;
	if ((*ts)->w > 1)
		size = (*ts)->w;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		(*ts)->error = 1;
	if (!(*ts)->error)
		str[size] = '\0';
	i = 0;
	if ((*ts)->minus == 1 && !(*ts)->error)
		ft_c_minus(ts, &str, c, size);
	else if ((*ts)->w > 1 && !(*ts)->error)
		ft_c_width(ts, &str, c, size);
	else if (!(*ts)->error)
		str[i] = c;
	if (!(*ts)->error)
		(*ts)->counter += write(1, str, size);
	if (!(*ts)->error)
		free(str);
}
