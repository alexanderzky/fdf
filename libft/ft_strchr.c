/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 13:11:57 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/15 17:32:40 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char *c_s;
	char c_c;

	c_s = (char *)s;
	c_c = (char)c;
	while (*c_s)
	{
		if (*c_s == c_c)
		{
			return (c_s);
		}
		c_s++;
	}
	if (*c_s == c_c)
	{
		return (c_s);
	}
	return (0);
}
