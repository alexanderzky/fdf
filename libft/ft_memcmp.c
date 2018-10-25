/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:04:20 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/13 13:53:02 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *c_string1;
	const unsigned char *c_string2;

	c_string1 = s1;
	c_string2 = s2;
	if (n == 0)
	{
		return (0);
	}
	while (n--)
	{
		if (*c_string1 != *c_string2)
		{
			return (*c_string1 - *c_string2);
		}
		else
		{
			c_string1++;
			c_string2++;
		}
	}
	return (0);
}
