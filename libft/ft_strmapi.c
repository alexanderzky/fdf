/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:58:00 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/16 14:36:18 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*c_s;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((c_s = ft_strnew(ft_strlen(s))) == NULL)
		return (0);
	while (s[i])
	{
		c_s[i] = (*f)(i, s[i]);
		i++;
	}
	c_s[i] = '\0';
	return (c_s);
}
