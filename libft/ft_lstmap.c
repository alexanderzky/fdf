/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:13:16 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/15 16:42:02 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *n_list;

	if (lst == NULL || f == NULL)
	{
		return (NULL);
	}
	if (lst)
	{
		n_list = (*f)(lst);
		n_list->next = ft_lstmap(lst->next, f);
		return (n_list);
	}
	return (NULL);
}
