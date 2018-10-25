/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:53:47 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 15:42:49 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_rgt_nbr(unsigned long n)
{
	while (n >= 10)
		n %= 10;
	return (n);
}

static void		ft_nbr_less(char *s, long n, long i)
{
	long			min;
	unsigned long	un;

	min = 0;
	s[0] = '-';
	un = (unsigned long)(n * -1);
	while (un > 0 && i >= 1)
	{
		if (un >= 10)
		{
			s[i] = ft_rgt_nbr(un) + '0';
			un /= 10;
		}
		else if (un < 10 && i == 1 && min != 1)
			s[i] = un + '0';
		else if (un < 10 && i > 1)
			s[i] = un + '0';
		--i;
	}
}

static void		ft_nbr_more(char *s, long n, long i)
{
	while (n >= 0 && i >= 0)
	{
		if (n < 10)
			s[i] = n + '0';
		else if (n >= 10)
		{
			s[i] = ft_rgt_nbr(n) + '0';
			n /= 10;
		}
		--i;
	}
}

char			*ft_itoa(long n)
{
	char	*s;
	long	i;

	i = ft_nbr_lngth(n);
	if ((s = ft_strnew(i)) == NULL)
		return (NULL);
	s[i--] = '\0';
	if (n < 0)
		ft_nbr_less(s, n, i);
	else if (n > 0)
		ft_nbr_more(s, n, i);
	else
		s[i] = '0';
	return (s);
}
