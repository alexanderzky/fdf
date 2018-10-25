/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 20:40:17 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/13 22:29:51 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_params	*ft_check_all(t_params *temp, const char **format, va_list vl)
{
	while (!ft_type_ch(format) && **format)
	{
		if (ft_flag_ch(*format))
			ft_flag_add(&temp, format);
		else if (ft_width_ch(format))
			ft_width_add(&temp, format, vl);
		else if (ft_prec_ch(format))
			ft_prec_add(&temp, format, vl);
		else if (ft_length_ch(format))
			ft_length_add(&temp, format);
		if (!ft_type_ch(format) && (ft_flag_ch(*format) || ft_width_ch(format)
			|| ft_prec_ch(format) || ft_length_ch(format)))
			(*format)++;
		else
			break ;
	}
	if (ft_type_ch(format))
		ft_type_add(&temp, format);
	else
		ft_buffer_add_wrong(&temp, format);
	if (temp->minus > -1 || (temp->p > -1 &&
			(temp->type != 's' && temp->type != 'c')))
		temp->zero = -1;
	return (temp);
}

void		ft_params_process(t_params *temp, va_list vl)
{
	if (temp->type == 'd' || temp->type == 'i')
		ft_length_influence_di(&temp, va_arg(vl, long));
	else if (temp->type == 'o')
		ft_length_influence_o(&temp, va_arg(vl, unsigned long));
	else if (temp->type == 'u')
		ft_length_influence_u(&temp, va_arg(vl, unsigned long));
	else if (temp->type == 'x')
		ft_length_influence_xx(&temp, va_arg(vl, unsigned long));
	else if (temp->type == 'c')
		ft_length_influence_c(&temp, va_arg(vl, unsigned int));
	else if (temp->type == 's')
		ft_length_influence_s(&temp, va_arg(vl, char*));
	else if (temp->type == 'p')
		ft_length_influence_p(&temp, va_arg(vl, unsigned long));
	else if (temp->type == 'b')
		ft_length_influence_b(&temp, va_arg(vl, unsigned long));
}

void		ft_percent(const char **format, t_params *temp, va_list vl)
{
	(*format)++;
	temp->meter++;
	temp = ft_check_all(temp, format, vl);
	ft_params_process(temp, vl);
	while (**format && !(ft_type_ch(format)) && !temp->skip && !temp->error)
	{
		temp->meter++;
		(*format)++;
	}
	if (**format && !temp->error)
	{
		temp->meter++;
		(*format)++;
	}
}

t_params	*ft_check_str(const char **format, va_list vl)
{
	size_t		f_len;
	t_params	*ts;
	long		format_limit;

	format_limit = ft_strlen(*format);
	if (!(ts = ft_create_specs()))
		return (NULL);
	while (ts->meter < format_limit && **format && !(ts->error))
	{
		if (**format == '%')
			ft_percent(format, ts, vl);
		else
		{
			f_len = ft_format_len(format);
			ts->counter += write(1, *format, f_len);
			while ((**format != '%') && **format)
			{
				(*format)++;
				ts->meter++;
			}
		}
		ft_clean_params(&ts);
	}
	return (ts);
}

int			ft_printf(const char *format, ...)
{
	va_list		vl;
	ssize_t		i;
	t_params	*flist;

	if (format == 0)
		return (0);
	va_start(vl, format);
	if (!(flist = ft_check_str(&format, vl)))
		return (-1);
	if (flist->error)
		return (-1);
	i = flist->counter;
	va_end(vl);
	free(flist);
	return ((int)i);
}
