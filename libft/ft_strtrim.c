/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:58:57 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/16 15:24:13 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sh_wsps(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*mem;
	long	i;
	long	start;
	long	end;

	end = 0;
	start = 0;
	i = 0;
	if (s == 0)
		return (0);
	while (ft_sh_wsps(s[i]) && s[i])
		i++;
	if (ft_strlen(s) == i)
		return (ft_strnew(1));
	start = i;
	while (s[i])
	{
		if (ft_sh_wsps(s[i]) == 0)
			end = i;
		i++;
	}
	if ((mem = ft_strsub(s, start, (end - start + 1))) == 0)
		return (0);
	return (mem);
}
