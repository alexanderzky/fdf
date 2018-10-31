/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:32:24 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/31 20:44:29 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_point(t_db *db)
{
	if (db->x_counter == 1 && db->y_counter == 1)
		mlx_pixel_put(db->mlx_ptr, db->win_ptr, db->arr[0][0].x,
				db->arr[0][0].y, 0xffffff);
}

void		ft_first_case(t_db *db, int x0, int y0, int i)
{
	int d;
	int x;
	int y;

	d = (db->dy << 1) - db->dx;
	x = x0 + db->sx;
	y = y0;
	mlx_pixel_put(db->mlx_ptr, db->win_ptr, x0, y0, db->color);
	while (i <= db->dx)
	{
		if (d > 0)
		{
			d += (db->dy - db->dx) << 1;
			y += db->sy;
		}
		else
			d += db->dy << 1;
		mlx_pixel_put(db->mlx_ptr, db->win_ptr, x, y, db->color);
		i++;
		x += db->sx;
	}
}

void		ft_sec(t_db *db, int x0, int y0, int i)
{
	int d;
	int y;
	int x;

	d = (db->dx << 1) - db->dy;
	x = x0;
	y = y0 + db->sy;
	mlx_pixel_put(db->mlx_ptr, db->win_ptr, x0, y0, db->color);
	while (i <= db->dy)
	{
		if (d > 0)
		{
			d += (db->dx - db->dy) << 1;
			x += db->sx;
		}
		else
			d += db->dx << 1;
		mlx_pixel_put(db->mlx_ptr, db->win_ptr, x, y, db->color);
		i++;
		y += db->sy;
	}
}

void		line(t_db *db, int x0, int x1, int y0)
{
	int y1;

	y1 = db->y1;
	db->dx = abs(x1 - x0);
	db->dy = abs(y1 - y0);
	db->sx = x1 >= x0 ? 1 : -1;
	db->sy = y1 >= y0 ? 1 : -1;
	if (abs(y1 - y0) <= abs(x1 - x0))
	{
		ft_first_case(db, x0, y0, 1);
	}
	else
	{
		ft_sec(db, x0, y0, 1);
	}
}
