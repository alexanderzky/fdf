/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_influences.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:42:53 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/15 19:04:50 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_length_influence_di(t_params **ts, long di)
{
	long size;

	if ((*ts)->length == -1)
		ft_itoa_base_dec((int)di, ts);
	else if ((*ts)->length == 0)
		ft_itoa_base_dec((signed char)di, ts);
	else if ((*ts)->length == 1)
		ft_itoa_base_dec((short)di, ts);
	else if ((*ts)->length == 2)
		ft_itoa_base_dec(di, ts);
	else if ((*ts)->length == 3)
		ft_itoa_base_dec((long long)di, ts);
	else if ((*ts)->length == 4)
		ft_itoa_base_dec((ssize_t)di, ts);
	else if ((*ts)->length == 5)
		ft_itoa_base_dec((intmax_t)di, ts);
	size = ft_di_size(ts);
	if (!(*ts)->error)
		ft_buffer_add_di(ts, size);
}

void	ft_length_influence_o(t_params **temp, unsigned long o)
{
	char *str;

	str = NULL;
	if ((*temp)->length == -1)
		str = ft_itoa_base((unsigned int)o, 8, 0);
	else if ((*temp)->length == 0)
		str = ft_itoa_base((unsigned char)o, 8, 0);
	else if ((*temp)->length == 1)
		str = ft_itoa_base((unsigned short)o, 8, 0);
	else if ((*temp)->length == 2)
		str = ft_itoa_base(o, 8, 0);
	else if ((*temp)->length == 3)
		str = ft_itoa_base((unsigned long long)o, 8, 0);
	else if ((*temp)->length == 4)
		str = ft_itoa_base((size_t)o, 8, 0);
	else
		str = ft_itoa_base((uintmax_t)o, 8, 0);
	if (str == NULL)
		(*temp)->error = 1;
	if (!(*temp)->error)
		ft_buffer_add_o(temp, str);
}

void	ft_length_influence_u(t_params **temp, unsigned long u)
{
	char *str;

	str = NULL;
	if ((*temp)->length == -1)
		str = ft_itoa_base((unsigned int)u, 10, 0);
	else if ((*temp)->length == 0)
		str = ft_itoa_base((unsigned char)u, 10, 0);
	else if ((*temp)->length == 1)
		str = ft_itoa_base((unsigned short)u, 10, 0);
	else if ((*temp)->length == 2)
		str = ft_itoa_base(u, 10, 0);
	else if ((*temp)->length == 3)
		str = ft_itoa_base((unsigned long long)u, 10, 0);
	else if ((*temp)->length == 4)
		str = ft_itoa_base((size_t)u, 10, 0);
	else if ((*temp)->length == 5)
		str = ft_itoa_base((uintmax_t)u, 10, 0);
	if (str == NULL)
		(*temp)->error = 1;
	if (!(*temp)->error)
		ft_buffer_add_u(temp, str);
}

void	ft_length_influence_xx(t_params **temp, unsigned long xx)
{
	char *str;

	str = NULL;
	if ((*temp)->length == -1)
		str = ft_itoa_base((unsigned int)xx, 16, 0);
	else if ((*temp)->length == 0)
		str = ft_itoa_base((unsigned char)xx, 16, 0);
	else if ((*temp)->length == 1)
		str = ft_itoa_base((unsigned short)xx, 16, 0);
	else if ((*temp)->length == 2)
		str = ft_itoa_base(xx, 16, 0);
	else if ((*temp)->length == 3)
		str = ft_itoa_base((unsigned long long)xx, 16, 0);
	else if ((*temp)->length == 4)
		str = ft_itoa_base((size_t)xx, 16, 0);
	else if ((*temp)->length == 5)
		str = ft_itoa_base((uintmax_t)xx, 16, 0);
	if (str == NULL)
		(*temp)->error = 1;
	if (!(*temp)->error)
		ft_buffer_add_xx(temp, str);
}

void	ft_length_influence_b(t_params **temp, unsigned long b)
{
	char *str;

	str = NULL;
	if ((*temp)->length == -1)
		str = ft_itoa_base((unsigned int)b, 2, 0);
	else if ((*temp)->length == 0)
		str = ft_itoa_base((unsigned char)b, 2, 0);
	else if ((*temp)->length == 1)
		str = ft_itoa_base((unsigned short)b, 2, 0);
	else if ((*temp)->length == 2)
		str = ft_itoa_base(b, 2, 0);
	else if ((*temp)->length == 3)
		str = ft_itoa_base((unsigned long long)b, 2, 0);
	else if ((*temp)->length == 4)
		str = ft_itoa_base((size_t)b, 2, 0);
	else if ((*temp)->length == 5)
		str = ft_itoa_base((uintmax_t)b, 2, 0);
	if (str == NULL)
		(*temp)->error = 1;
	if (!(*temp)->error)
		ft_buffer_add_o(temp, str);
}
