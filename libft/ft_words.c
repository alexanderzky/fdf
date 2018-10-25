/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:32:57 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/17 15:58:19 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_words(char const *s, char c)
{
	size_t	w_count;
	size_t	is_not_c;
	long	i;

	i = 0;
	is_not_c = 0;
	w_count = 0;
	while (i < ft_strlen(s))
	{
		while (s[i] != c && s[i] != '\0')
			++i && ++is_not_c;
		if (is_not_c)
			++w_count;
		++i;
		is_not_c = 0;
	}
	if (w_count == 0 && ft_has_ch(s, c))
		return (1);
	return (w_count);
}
