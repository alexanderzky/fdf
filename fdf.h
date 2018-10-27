/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:33:07 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/27 16:56:30 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

#include "./libft/libft.h"
# include <fcntl.h>

typedef struct		s_point
{
	double				x;
	double				y;
	double				z;
	long				color;
	double				x_copy;
	double				y_copy;
	double				z_copy;
}					t_p;

typedef struct		s_db
{
	int				fd;
	char 			*line;
	size_t			x_counter;
	size_t			x_4cpmr;
	size_t			y_counter;
	struct s_point **arr;
	struct s_point	*point;

}					t_db;



#endif //FDF_FDF_H
