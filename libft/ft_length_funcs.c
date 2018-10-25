/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:32:01 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 20:32:43 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strsimplelen(const wchar_t *s)
{
	long string_i;

	string_i = 0;
	while (s[string_i])
	{
		string_i++;
	}
	return (string_i);
}

long	ft_precstrlen(t_params **temp, wchar_t *str)
{
	int		i;
	long	charsize;
	long	precision_counter;
	long	k;

	i = 0;
	k = (*temp)->p;
	precision_counter = 0;
	if ((*temp)->p < 1)
		return (ft_strsimplelen(str));
	while (str[i])
	{
		charsize = ft_charwlen(str[i]);
		if (charsize <= k)
		{
			k -= charsize;
			precision_counter++;
		}
		else
			break ;
	}
	return (precision_counter);
}

long	ft_precwidstrlen(t_params **temp, wchar_t *str)
{
	int		i;
	long	charsize;
	long	precision_counter;
	long	k;

	i = 0;
	precision_counter = 0;
	k = (*temp)->p;
	if ((*temp)->p < 1)
		return (ft_strwlen(str));
	while (str[i])
	{
		charsize = ft_charwlen(str[i]);
		if (charsize <= k)
		{
			k -= charsize;
			precision_counter += charsize;
		}
		else
			break ;
	}
	return (precision_counter);
}
