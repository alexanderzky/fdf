/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:26:04 by ozalisky          #+#    #+#             */
/*   Updated: 2017/11/21 14:38:10 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *c_alst;
	t_list *next_alst;

	if (*alst == NULL || del == NULL || alst == NULL)
		return ;
	c_alst = *alst;
	while (c_alst)
	{
		next_alst = c_alst->next;
		(*del)(c_alst->content, c_alst->content_size);
		free(c_alst);
		c_alst = next_alst;
	}
	*alst = NULL;
}
