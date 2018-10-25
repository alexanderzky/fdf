/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:50:49 by ozalisky          #+#    #+#             */
/*   Updated: 2018/05/14 21:51:01 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_params	*ft_create_specs(void)
{
	t_params *temp;

	if (!(temp = (t_params*)ft_memalloc(sizeof(t_params))))
		return (NULL);
	temp->minus = -1;
	temp->plus = -1;
	temp->space = -1;
	temp->hash = -1;
	temp->zero = -1;
	temp->w = -1;
	temp->p = -1;
	temp->x = -1;
	temp->length = -1;
	temp->counter = 0;
	temp->skip = 0;
	temp->meter = 0;
	temp->freeme = 0;
	temp->dminus = 0;
	return (temp);
}

void		ft_clean_params(t_params **temp)
{
	(*temp)->minus = -1;
	(*temp)->plus = -1;
	(*temp)->space = -1;
	(*temp)->hash = -1;
	(*temp)->zero = -1;
	(*temp)->w = -1;
	(*temp)->p = -1;
	(*temp)->length = -1;
	(*temp)->type = -1;
	(*temp)->x = -1;
	(*temp)->skip = 0;
	(*temp)->meter = 0;
	(*temp)->freeme = 0;
	(*temp)->dminus = 0;
	(*temp)->ostr = NULL;
}
