/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 16:20:45 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/16 13:55:06 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*csrc;
	char		*cdst;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	i = -1;
	csrc = (char *)src;
	cdst = (char *)dst;
	if (csrc < cdst)
	{
		while ((long)(--len) >= 0)
			*(cdst + len) = *(csrc + len);
	}
	else
	{
		while (++i < len)
			*(cdst + i) = *(csrc + i);
	}
	return (dst);
}
