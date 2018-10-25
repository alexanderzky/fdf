/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:57:34 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/16 14:36:05 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	size_t	s_i;
	size_t	mem_i;

	s_i = 0;
	mem_i = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	if ((mem = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == 0)
		return (0);
	while (s1[s_i])
	{
		mem[mem_i] = s1[s_i];
		mem_i++;
		s_i++;
	}
	s_i = 0;
	while (s2[s_i])
	{
		mem[mem_i] = s2[s_i];
		mem_i++;
		s_i++;
	}
	mem[mem_i] = '\0';
	return (mem);
}
