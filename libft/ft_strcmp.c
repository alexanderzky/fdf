/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:46:39 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/15 17:34:08 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *c_s1;
	unsigned char *c_s2;

	c_s1 = (unsigned char*)s1;
	c_s2 = (unsigned char*)s2;
	while (*c_s1 == *c_s2)
	{
		if (0 == *c_s1)
		{
			return (0);
		}
		++c_s1;
		++c_s2;
	}
	return (*c_s1 < *c_s2 ? *c_s1 - *c_s2 : *c_s1 - *c_s2);
}
