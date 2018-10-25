/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:58:09 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/15 13:59:02 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*c_s1;
	unsigned char	*c_s2;
	size_t			i;

	c_s1 = (unsigned char*)s1;
	c_s2 = (unsigned char*)s2;
	i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if (n == 0)
		return (1);
	while (i < n)
	{
		if (*c_s1 == *c_s2)
		{
			if ((*c_s1 == '\0' && *c_s2 == '\0') || i == n - 1)
				return (1);
		}
		if (*c_s1 != *c_s2)
			return (0);
		++c_s1;
		++c_s2;
		++i;
	}
	return (0);
}
