/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 12:12:14 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/16 13:21:49 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*cdst;
	const char		*csrc;

	if (!dst && !src)
		return (NULL);
	cdst = dst;
	csrc = src;
	i = 0;
	while (n--)
	{
		(cdst[i] = csrc[i]);
		++i;
	}
	return (dst);
}
