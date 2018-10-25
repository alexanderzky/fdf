/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:13:10 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 22:04:48 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size(unsigned long new, int base)
{
	int size;

	size = 0;
	if (new == 0)
		return (1);
	while (new)
	{
		new /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(unsigned long value, int base, int i)
{
	static char	val[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'a', 'b', 'c', 'd', 'e', 'f'};
	long		size;
	long		j;
	char		*str;

	size = ft_size(value, base);
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	if (value == 0)
	{
		str[0] = '0';
		return (str);
	}
	i = (int)size - 1;
	while (value)
	{
		j = value % base;
		str[i] = val[j];
		value = value / base;
		i--;
	}
	return (str);
}
