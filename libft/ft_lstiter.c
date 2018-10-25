/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:05:10 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/14 12:46:45 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *next_lst;

	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		next_lst = lst->next;
		(*f)(lst);
		lst = next_lst;
	}
}
