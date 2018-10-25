/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:59:02 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/09 13:18:05 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	unsigned int i;
	unsigned int f;

	i = 0;
	if (0 == ft_strlen(little))
	{
		return ((char *)big);
	}
	while ('\0' != big[i])
	{
		f = 0;
		while (big[i + f] == little[f])
		{
			++f;
			if ('\0' == little[f])
			{
				return ((char *)big + i);
			}
		}
		++i;
	}
	return (0);
}
