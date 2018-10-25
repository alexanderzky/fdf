/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:24:33 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/14 18:13:13 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c_s1;
	unsigned char	*c_s2;
	size_t			i;

	c_s1 = (unsigned char*)s1;
	c_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*c_s1 == *c_s2)
		{
			if ((*c_s1 == '\0' && *c_s2 == '\0') || i == n - 1)
				return (0);
		}
		if (*c_s1 != *c_s2)
		{
			return (*c_s1 - *c_s2);
		}
		++c_s1;
		++c_s2;
		++i;
	}
	return (0);
}
