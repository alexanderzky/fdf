/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:37:49 by ozalisky          #+#    #+#             */
/*   Updated: 2018/06/06 19:07:14 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_charwlen(const wchar_t c)
{
	if (c < 128)
		return (1);
	else if (c > 127 && c < 2048)
		return (2);
	else if (c > 2047 && c < 65536)
		return (3);
	else if (c > 65535 && c < 2097152)
		return (4);
	return (1);
}

long	ft_strwlen(const wchar_t *s)
{
	long string_i;
	long counter;

	counter = 0;
	string_i = 0;
	while (s[string_i])
	{
		if (s[string_i] < 128)
			counter++;
		else if (s[string_i] > 127 && s[string_i] < 2048)
			counter += 2;
		else if (s[string_i] > 2047 && s[string_i] < 65536)
			counter += 3;
		else if (s[string_i] > 65535 && s[string_i] < 2097152)
			counter += 4;
		string_i++;
	}
	return (counter);
}

long	ft_strlen(const char *s)
{
	long string_i;

	string_i = 0;
	if (!s)
		return (string_i);
	while (s[string_i])
	{
		string_i++;
	}
	return (string_i);
}
