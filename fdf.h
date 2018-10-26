/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:33:07 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/26 18:24:11 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

#include "./libft/libft.h"
# include <fcntl.h>

typedef struct		s_point
{
	long				x;
	long				y;
	long				z;
	long				color;
	struct s_point *next;
}					t_p;

typedef struct		s_db
{
	int				fd;
	char 			*line;
	size_t			x_counter;
	size_t			x_4cpmr;
	size_t			y_counter;
	struct s_point	*point;
}					t_db;



#endif //FDF_FDF_H
