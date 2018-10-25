/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_influence_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:09:34 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/12 18:09:34 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_length_influence_s(t_params **temp, char *s)
{
	if ((*temp)->length == 2)
		ft_buffer_add_ws(temp, (wchar_t*)s);
	else
		ft_buffer_add_s(temp, s);
}

void	ft_length_influence_c(t_params **temp, unsigned int c)
{
	if ((*temp)->length == 2 && MB_CUR_MAX > 1)
		ft_buffer_add_wc(temp, (wchar_t)c);
	else
		ft_buffer_add_c(temp, c);
}

void	ft_length_influence_p(t_params **temp, unsigned long xx)
{
	char *str;

	str = NULL;
	if ((*temp)->length == -1)
		str = ft_itoa_base(xx, 16, 0);
	else if ((*temp)->length == 0)
		str = ft_itoa_base((unsigned char)xx, 16, 0);
	else if ((*temp)->length == 3)
		str = ft_itoa_base((unsigned long long)xx, 16, 0);
	else if ((*temp)->length == 1)
		str = ft_itoa_base((unsigned short)xx, 16, 0);
	else if ((*temp)->length == 2)
		str = ft_itoa_base(xx, 16, 0);
	else if ((*temp)->length == 5)
		str = ft_itoa_base((uintmax_t)xx, 16, 0);
	else if ((*temp)->length == 4)
		str = ft_itoa_base((size_t)xx, 16, 0);
	if (str == NULL)
		(*temp)->error = 1;
	if (!(*temp)->error)
		ft_buffer_add_p(temp, str);
}
