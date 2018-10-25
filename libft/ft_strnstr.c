/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:19:33 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/13 14:01:05 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	unsigned int	i;
	unsigned int	f;
	size_t			c_len;

	i = 0;
	c_len = len;
	if (0 == ft_strlen(lil))
	{
		return ((char *)big);
	}
	while ('\0' != c_len && '\0' != big[i])
	{
		f = 0;
		while (big[i + f] == lil[f])
		{
			++f;
			if ('\0' == lil[f] && (f + i <= len))
			{
				return ((char *)big + i);
			}
		}
		++i;
		--c_len;
	}
	return (0);
}
