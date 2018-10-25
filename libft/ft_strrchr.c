/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:45:24 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/13 11:29:11 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *c_s;
	char *f_c;
	char c_c;

	c_s = (char *)s;
	f_c = NULL;
	c_c = (char)c;
	while (*c_s)
	{
		if (*c_s == c_c)
		{
			f_c = c_s;
		}
		++c_s;
	}
	if (*c_s == c_c)
	{
		f_c = c_s;
	}
	return (f_c);
}
