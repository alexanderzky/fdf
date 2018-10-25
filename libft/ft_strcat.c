/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:49:16 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/15 17:31:31 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	char			*copy_s1;
	const char		*copy_s2;
	unsigned int	string_i;
	unsigned int	string_i2;

	copy_s1 = s1;
	copy_s2 = s2;
	string_i = 0;
	string_i2 = 0;
	while (copy_s1[string_i] != '\0')
	{
		string_i++;
	}
	while (copy_s2[string_i2] != '\0')
	{
		copy_s1[string_i] = copy_s2[string_i2];
		string_i++;
		string_i2++;
	}
	copy_s1[string_i] = '\0';
	return (s1);
}
