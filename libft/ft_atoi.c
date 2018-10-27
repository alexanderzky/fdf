/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:41:26 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/08 21:52:21 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atoi(const char *str)
{
	long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while (ft_iscntrlspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (ft_issign(*str))
		str++;
	while (*str && ft_isdigit(*str))
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
			&& (*str - '0') > 7)) && sign == 1)
			return (-1);
		if ((result > 922337203685477580 || (result == 922337203685477580
			&& (*str - '0') > 8)) && sign == -1)
			return (0);
		result = result * 10 + (*str - 48);
		++str;
	}
	return (sign * result);
}
