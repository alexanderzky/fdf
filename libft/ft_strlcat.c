/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:32:47 by ozalisky          #+#    #+#             */
/*   Updated: 2018/04/21 18:54:56 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*c_dst;
	char		*c_src;
	size_t		c_size;
	size_t		dst_size;

	c_dst = (char *)dst;
	c_src = (char *)src;
	while ((*c_dst != '\0'))
		c_dst++;
	dst_size = c_dst - dst;
	c_size = size - dst_size;
	if (c_size == 0)
		return (dst_size + ft_strlen(c_src));
	while (*c_src != '\0')
	{
		if (c_size != 1)
		{
			*c_dst++ = *c_src;
			c_size--;
		}
		c_src++;
	}
	*c_dst = '\0';
	return (dst_size + (c_src - src));
}
