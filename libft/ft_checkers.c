/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:47:18 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 15:06:30 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_type_ch(const char **format)
{
	if (**format == 'd' || **format == 'D' || **format == 's' || **format == 'S'
		|| **format == 'u' || **format == 'U' || **format == 'x' ||
		**format == 'X' || **format == 'c' || **format == 'C' || **format == 'p'
		|| **format == 'i' || **format == 'o' || **format == 'O' ||
		**format == 'b' || **format == 'B')
		return (1);
	return (0);
}

int				ft_prec_ch(const char **format)
{
	if (**format == '.')
		return (1);
	return (0);
}

int				ft_width_ch(const char **format)
{
	if ((**format > 48 && **format < 58) || **format == 42)
		return (1);
	return (0);
}

int				ft_length_ch(const char **format)
{
	if (**format == 'h' || **format == 'l' || **format == 'j' ||
			**format == 'z')
		return (1);
	return (0);
}

int				ft_flag_ch(const char *format)
{
	if (*format == '-' || *format == '+' || *format == ' ' || *format == '#'
		|| *format == '0')
		return (1);
	return (0);
}
