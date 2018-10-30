/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:31:56 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/30 21:01:09 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "fdf.h"
# define PI = 3.14159265359

void	ft_init(t_db *db)
{
	db->line = NULL;
	db->x_counter = 0;
	db->y_counter = 0;
	db->x_4cpmr = 0;
	db->point = NULL;
	db->scale = 10;
	db->an_z = 10;
	db->an_x = 12;
	db->an_y = 7;
	db->increment = 5;
	db->size_x = 1000;
	db->size_y = 1000;
	db->mlx_ptr = mlx_init();
	db->win_ptr = mlx_new_window(db->mlx_ptr, db->size_x, db->size_y, "mlx 42");
	db->color = 0xffffff;
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	ft_parse_hex()
{

}

void	ft_check_map(t_db *db, char *file)
{
	int i;
	if ((db->fd = open(file, O_RDONLY)) < 0)
		ft_error("can't read");
	while ( (i = get_next_line(db->fd, &db->line)) > 0)
	{
		if (db->line[0] == '\0')
			ft_error("empty line");
		if (db->x_counter == 0)
			db->x_counter = ft_words(db->line, ' ');
		if (db->x_counter != ft_words(db->line, ' '))
			ft_error("wrong quantity of xs");
		++db->y_counter;
		free(db->line);
	}
	if (i < 0)
	{
		ft_error("can't read");
	}
	close(db->fd);
}

int	ft_getnbr(char *str)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		result = result * (-1);
	return (result);
}

void	ft_save_map(t_db *db, char *file)
{
	long	i;
	int 	y;
	int 	x;

	x = 0;
	y = 0;
	i = 0;
	if ((db->fd = open(file, O_RDONLY)) < 0)
		ft_error("can't read");
	db->arr = ft_memalloc(sizeof(t_p) * db->y_counter);
	while (get_next_line(db->fd, &db->line) > 0)
	{
		db->arr[y] = ft_memalloc(sizeof(t_p) * db->x_counter);
		while (i < ft_strlen(db->line))
		{
			if (ft_isdigit(db->line[i]))
			{
				db->arr[y][x].z = ft_atoi(&db->line[i]);
				db->arr[y][x].x = x;
				db->arr[y][x].y = y;
				db->arr[y][x].x_copy = x;
				db->arr[y][x].y_copy = y;
				db->arr[y][x].z_copy = db->arr[y][x].z;
				++x;
				while (db->line[i] != ' ' && db->line[i] != ',')
					++i;
				continue ;
			}
			else if (db->line[i] == ',')
				ft_parse_hex();  //make this!
			else if (db->line[i] != ' ' && db->line[i] != '-')
				ft_error("not a valid map\n");
			i += ft_nbr_lngth((long)db->arr[y][x].z) ?
				 ft_nbr_lngth((long)db->arr[y][x].z) : 1;
		}
		x = 0;
		i = 0;
		++y;

		free(db->line);
	}
	close(db->fd);
}


void		calc_mod1(t_db *db, int i, int z)
{
	(db->arr[i][z]).y = ((db->arr[i][z]).y_copy * (sin(db->alp) *
			cos(db->gam) + cos(db->alp) * cos(db->bet) * sin(db->gam)) +
					(db->arr[i][z]).y_copy * (cos(db->alp) * cos(db->bet) *
					cos(db->gam) - sin(db->alp) * sin(db->gam)) -
					(db->arr[i][z]).z * cos(db->alp) * sin(db->bet))  ;
}

void		calc_mod2(t_db *db, int i, int z)
{
	(db->arr[i][z]).z = ((db->arr[i][z]).x_copy *
			(sin(db->bet) * sin(db->alp)) + (db->arr[i][z]).y_copy *
			sin(db->bet) * cos(db->alp) + (db->arr[i][z]).z *
			cos(db->bet));
}

void		rotation(t_db *db)
{
	int		y;
	int		x;

	y = -1;
	db->alp = 3.14159265359 * (db->an_z) / 180;
	db->bet = 3.14159265359 * (db->an_y) / 180;
	db->gam = 3.14159265359 * (db->an_x) / 180;
	while (++y < db->y_counter)
	{
		x = -1;
		while (++x < db->x_counter)
		{
			db->arr[y][x].z = ((db->arr[y][x]).z_copy);
		db->arr[y][x].x = (db->arr[y][x].x_copy * (cos(db->alp) * cos(db->gam) - sin(db->alp) *
		cos(db->bet) * sin(db->gam)) + (db->arr[y][x]).y_copy * (-cos(db->alp) *
				sin(db->gam) - sin(db->alp) * cos(db->bet) * cos(db->gam)) +
						(db->arr[y][x]).y * sin(db->alp) * sin(db->bet));
			calc_mod1(db, y, x);
			calc_mod2(db, y, x);
		}
	}
}

void 	key_hook(int keycode, t_db *db)
{
	if (keycode == 53)
	{
		mlx_destroy_window(db->mlx_ptr, db->win_ptr);
		exit(0);
	}
}

int getColor()
{

}

void line (t_db *db, int x0, int x1, int y0, int y1, color)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x1 >= x0 ? 1 : -1;
	int sy = y1 >= y0 ? 1 : -1;

	if (dy <= dx)
	{
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;
		mlx_pixel_put(db->mlx_ptr, db->win_ptr,x0, y0, db->color);
		for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
		{
			if ( d >0)
			{
				d += d2;
				y += sy;
			}
			else
				d += d1;
			mlx_pixel_put(db->mlx_ptr, db->win_ptr,x, y, db->color);
		}
	}
	else
	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		mlx_pixel_put(db->mlx_ptr, db->win_ptr, x0, y0, color);
		for (int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
		{
			if (d > 0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;
			mlx_pixel_put(db->mlx_ptr, db->win_ptr, x, y, color);
		}
	}
}


int		main(int argc, char **argv)
{
	t_db db; // check if only 1 point
	ft_init(&db);
	if (argc != 2)
		ft_error("argc!=2");
	ft_check_map(&db, argv[1]);
	ft_save_map(&db, argv[1]);
	int x = 0;
	int y = 0;
	mlx_hook(db.win_ptr, 2, 0, key_hook, &db);
	rotation(&db);
//	while (y < db.y_counter)
//	{
//		while (x < db.x_counter)
//		{
//			if (db.arr[y][x].z == 0)
//				printf(" ");
//			printf("%.0f", db.arr[y][x].z);
//			printf(" ");
//			++x;
//		}
//		printf("\n");
//		x = 0;
//		++y;
//	}
	y = 0;
	x = 0;
	if (db.x_counter == 1 && db.y_counter == 1)
		mlx_pixel_put(db.mlx_ptr, db.win_ptr,db.arr[0][0].x, db.arr[0][0].y,  0xffffff);
	while (y < db.y_counter)
	{
		while (x < db.x_counter)
		{
			db.color = (db.arr[y][x].z > 100) ? 0x0000ff : 0xffffff;

			if (x + 1 < db.x_counter)
			{
				line(&db, db.arr[y][x].x*db.scale, db.arr[y][x + 1].x*db.scale,
					 db.arr[y][x].y*db.scale, db.arr[y][x+1].y*db.scale, db.color);
			}


			if (y + 1 < db.y_counter)
			{
				line(&db, db.arr[y][x].x*db.scale, db.arr[y+1][x].x*db.scale,
					 db.arr[y][x].y*db.scale, db.arr[y+1][x].y*db.scale, db.color);
			}
			++x;
		}
		x = 0 ;
		++y;
	}

	mlx_loop(db.mlx_ptr);
	exit(0);
}