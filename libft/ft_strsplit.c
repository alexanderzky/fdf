/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:58:33 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/17 15:58:17 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**mem;
	size_t	start;
	size_t	i;
	size_t	mem_i;

	mem_i = 0;
	i = 0;
	start = 0;
	if (!s || !c)
		return (NULL);
	if ((mem = (char **)ft_memalloc((ft_words(s, c) + 1)
		* sizeof(char*))) == NULL)
		return (NULL);
	while (mem_i < ft_words(s, c))
	{
		while (s[i] == c)
			++i;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if ((mem[mem_i++] = ft_strsub(s, start, i - start)) == NULL)
			return (ft_arrdel(mem, ft_words(s, c)) ? (NULL) : (NULL));
		i++;
	}
	return (mem);
}
