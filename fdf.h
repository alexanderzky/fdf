/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:33:07 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/24 22:07:08 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

#include "./libft/libft.h"

struct				s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point *next;
}					t_p;

struct				s_db
{

}					t_db;



#endif //FDF_FDF_H
