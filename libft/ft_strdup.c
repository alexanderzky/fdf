/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 18:00:04 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/15 18:01:18 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dst;

	size = ft_strlen(s1);
	if ((dst = malloc(size + 1)) == NULL)
	{
		return (NULL);
	}
	ft_strcpy(dst, s1);
	return (dst);
}
