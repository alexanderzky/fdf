/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:58:45 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/09 17:49:36 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (s == 0)
		return (0);
	if ((mem = ft_strnew(len)) == NULL)
		return (NULL);
	while (len)
	{
		mem[i] = s[start];
		++i;
		--len;
		start++;
	}
	mem[i] = '\0';
	return (mem);
}
