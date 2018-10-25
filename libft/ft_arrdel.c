/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:12:32 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/15 15:53:52 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arrdel(char **ar, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&ar[i]);
		++i;
	}
	free(ar);
	ar = NULL;
	return (0);
}
