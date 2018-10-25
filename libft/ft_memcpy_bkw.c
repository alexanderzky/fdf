/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_bkw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:49:04 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/16 13:22:32 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_bkw(void *dst, const void *src, size_t n)
{
	char			*cdst;
	const char		*csrc;

	if (!dst && !src)
		return (NULL);
	cdst = dst;
	csrc = src;
	while (n)
	{
		(cdst[n] = csrc[n]);
		n--;
	}
	return (dst);
}
