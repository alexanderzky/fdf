/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:31:56 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/31 20:46:33 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		calc_mod2(t_db *db, int i, int z)
{
	(db->arr[i][z]).z = ((db->arr[i][z]).x_copy *
	(sin(db->bet) * sin(db->alp)) + (db->arr[i][z]).y_copy *
	sin(db->bet) * cos(db->alp) + (db->arr[i][z]).z * cos(db->bet));
}

void		rotation(t_db *db)
{
	int	y;
	int	x;

	y = -1;
	db->alp = 3.14159265359 * (db->an_z) / 180;
	db->bet = 3.14159265359 * (db->an_y) / 180;
	db->gam = 3.14159265359 * (db->an_x) / 180;
	while (++y < (int)db->y_counter)
	{
		x = -1;
		while (++x < (int)db->x_counter)
		{
			db->arr[y][x].z = ((db->arr[y][x]).z_copy);
			db->arr[y][x].x = (db->arr[y][x].x_copy * (cos(db->alp) *
			cos(db->gam) - sin(db->alp) * cos(db->bet) * sin(db->gam)) +
			(db->arr[y][x]).y_copy * (-cos(db->alp) * sin(db->gam) -
			sin(db->alp) * cos(db->bet) * cos(db->gam)) + (db->arr[y][x]).y *
			sin(db->alp) * sin(db->bet)) + db->size_x / 20 -
			(int)db->x_counter / 2;
			calc_mod1(db, y, x);
			calc_mod2(db, y, x);
		}
	}
}

static int	exit_x(void *par)
{
	par = NULL;
	exit(0);
	return (0);
}

void		ft_draw(t_db *db, int y, int x)
{
	while (y < (int)db->y_counter)
	{
		while (x < (int)db->x_counter)
		{
			if (x + 1 < (int)db->x_counter)
			{
				db->y1 = db->arr[y][x + 1].y * db->scale;
				line(db, db->arr[y][x].x * db->scale, db->arr[y][x + 1].x *
				db->scale, db->arr[y][x].y * db->scale);
			}
			if (y + 1 < (int)db->y_counter)
			{
				db->y1 = db->arr[y + 1][x].y * db->scale;
				line(db, db->arr[y][x].x * db->scale, db->arr[y + 1][x].x *
				db->scale, db->arr[y][x].y * db->scale);
			}
			++x;
		}
		x = 0;
		++y;
	}
}

int			main(int argc, char **argv)
{
	t_db	db;

	ft_init(&db);
	if (argc != 2)
		ft_error("argc!=2");
	ft_check_map(&db, argv[1]);
	ft_save_map(&db, argv[1]);
	ft_init_mlx(&db);
	mlx_hook(db.win_ptr, 2, 0, key_hook, &db);
	mlx_hook(db.win_ptr, 17, 1L << 17, exit_x, &db);
	rotation(&db);
	if (db.x_counter == 1 && db.y_counter == 1)
		ft_point(&db);
	ft_draw(&db, 0, 0);
	mlx_loop(db.mlx_ptr);
	exit(0);
}
