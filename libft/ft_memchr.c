/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:34:30 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/11 15:47:26 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		c_c;
	const char	*c_string;

	c_c = (char)c;
	c_string = s;
	while (n > 0)
	{
		if (*c_string == c_c)
			return ((void *)c_string);
		c_string++;
		n--;
	}
	return (0);
}
