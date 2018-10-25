/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:58:22 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/15 18:03:25 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*mem;
	size_t	c_size;

	c_size = size + 1;
	if ((mem = (char *)malloc(c_size * sizeof(char))) == NULL)
		return (NULL);
	ft_memset(mem, '\0', c_size);
	return (mem);
}
