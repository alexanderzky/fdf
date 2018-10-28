/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:33:07 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/28 20:03:44 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

#include "./libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# define PI = 3.14159265359

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
	int 			scale;
	double			alp;
	double			bet;
	double 			gam;
	int 			color;
	int 			an_z;
	int 			an_y;
	int 			an_x;
	int 			increment;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_db;



#endif //FDF_FDF_H
