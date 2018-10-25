/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:22:11 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/13 11:04:38 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int s1_i;
	unsigned int s2_i;

	s1_i = ft_strlen(s1);
	s2_i = 0;
	while (s2_i < n && s2[s2_i])
	{
		s1[s1_i] = s2[s2_i];
		s1_i++;
		s2_i++;
	}
	s1[s1_i] = '\0';
	return (s1);
}
