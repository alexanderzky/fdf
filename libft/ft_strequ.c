/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:56:53 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/16 14:29:09 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned char *c_s1;
	unsigned char *c_s2;

	if (!s1 && !s2)
		return (1);
	if ((!s1 && s2) || (s1 && !s2))
		return (0);
	c_s1 = (unsigned char*)s1;
	c_s2 = (unsigned char*)s2;
	if (s1 == 0 || s2 == 0)
		return (0);
	while (*c_s1 == *c_s2)
	{
		if (0 == *c_s1)
		{
			return (1);
		}
		++c_s1;
		++c_s2;
	}
	return (0);
}
