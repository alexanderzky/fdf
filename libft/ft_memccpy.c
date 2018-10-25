/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:48:29 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/13 10:14:31 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*cdst;
	const unsigned char	*csrc;
	unsigned char		c_c;

	c_c = (unsigned char)c;
	cdst = (unsigned char *)dst;
	csrc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cdst[i] = csrc[i];
		if (cdst[i] == c_c)
			return (cdst + i + 1);
		++i;
	}
	return (NULL);
}
