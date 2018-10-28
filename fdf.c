/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:31:56 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/28 20:30:41 by ozalisky         ###   ########.fr       */
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
	db->an_z = 15;
	db->an_x = 30;
	db->an_y = 35;
	db->increment = 5;
	db->mlx_ptr = mlx_init();
	db->win_ptr = mlx_new_window(db->mlx_ptr, 500,500, "mlx 42");
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

void	ft_parse_hex()
{

}

//void	ft_save_map(t_db *db)
//{
//	size_t line_len;
//	size_t i;
//	t_p *temp_point;
//	t_p *prev_point;
//
//	i = 0;
//	prev_point = NULL;
//	line_len = (size_t)ft_strlen(db->line);
//	while (i < line_len)
//	{
//		if (db->line[i] == ',')
//			ft_parse_hex();  //make this!
//		if (ft_isalpha(db->line[i]))
//			ft_error("not a map\n");
//		else if (ft_isdigit(db->line[i]))
//		{
//			temp_point = db->point;
//			while (temp_point != NULL) //add last one point
//			{
//				prev_point = temp_point;
////				temp_point = temp_point->next;
//			}
//			temp_point = ft_memalloc(sizeof(t_p));
//			temp_point->z = (double)ft_atoi(&db->line[i]);
//			temp_point->x = db->x_counter++;
//			temp_point->y = db->y_counter;
//			if (!db->point)
//				db->point = temp_point;
////			else if (prev_point)
////				prev_point->next = temp_point;
//		}
//		i += ft_nbr_lngth(temp_point->z) ? ft_nbr_lngth(temp_point->z) : 1;
//	}
//	if (db->x_4cpmr == 0)
//	{
//		db->x_4cpmr = db->x_counter;
//	}
//	else if (db->x_4cpmr != db->x_counter)
//	{
//		ft_error("wrong quantity of xs");
//	}
//	db->x_counter = 0;
//	++db->y_counter;
//}

void	ft_check_map(t_db *db, char *file)
{
	if ((db->fd = open(file, O_RDONLY)) < 0)
		ft_error("can't read");
	while (get_next_line(db->fd, &db->line) > 0)
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

}


void		calc_mod1(t_db *db, int i, int z)
{
	(db->arr[i][z]).y = ((db->arr[i][z]).y_copy * (sin(db->alp) *
			cos(db->gam) + cos(db->alp) * cos(db->bet) * sin(db->gam)) +
					(db->arr[i][z]).y_copy * (cos(db->alp) * cos(db->bet) *
					cos(db->gam) - sin(db->alp) * sin(db->gam)) -
					(db->arr[i][z]).z * cos(db->alp) * sin(db->bet));
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
	int		i;
	int		z;

	i = -1;
	db->alp = 3.14159265359 * (db->an_z) / 180;
	db->bet = 3.14159265359 * (db->an_y) / 180;
	db->gam = 3.14159265359 * (db->an_x) / 180;
	while (++i < db->y_counter)
	{
		z = -1;
		while (++z < db->x_counter)
		{
//			db->arr[i][z].z = 20;
			db->arr[i][z].z = ((db->arr[i][z]).z_copy);
db->arr[i][z].x = (db->arr[i][z].x_copy * (cos(db->alp) * cos(db->gam) - sin(db->alp) * cos(db->bet) * sin(db->gam)) + (db->arr[i][z]).y_copy * (-cos(db->alp) * sin(db->gam) - sin(db->alp) * cos(db->bet) * cos(db->gam)) + (db->arr[i][z]).y * sin(db->alp) * sin(db->bet));
			calc_mod1(db, i, z);
			calc_mod2(db, i, z);
		}
	}
}

void line (t_db *db, int x0, int x1, int y0, int y1, int color)
{
	int dx = db->arr[y0][x1 + 1].x - db->arr[y0][x0].x;
	int dy = db->arr[y1 + 1][x0].y - db->arr[y0][x0].y;
	int d = (dy << 1) - dx;
	int d1 = dy << 1;
	int d2 = (dy - dx) << 1;

	mlx_pixel_put(db->mlx_ptr, db->win_ptr, db->arr[y0][x0].x * db->scale,
				  db->arr[y0][x0].y * db->scale, db->color);

	int x_new = db->arr[y0][x0].x + 1;
	int y_new = db->arr[y0][x0].y;
	while (x_new <= db->arr[y0][x1 + 1].x)
	{
		if ( d > 0)
		{
			d += d2;
			y_new += 1;
		}
		else
			d += d1;

		mlx_pixel_put(db->mlx_ptr, db->win_ptr, db->arr[y_new][x_new].x * db->scale,
					  db->arr[y_new][x_new].y * db->scale, db->color);

		x_new++;
	}
}



void	key_hook_rot(t_db *db, int keycode)
{
	if (keycode == 2)
		db->an_x += db->increment;
	else if (keycode == 0)
		db->an_x -= db->increment;
	else if (keycode == 13)
		db->an_y += db->increment;
	else if (keycode == 1)
		db->an_y -= db->increment;
	else if (keycode == 12)
		db->an_z += db->increment;
	else if (keycode == 14)
		db->an_z -= db->increment;
//	db->alp = 3.14159265359 * (db->an_z) / 180;
//	db->bet = 3.14159265359 * (db->an_y) / 180;
//	db->gam = 3.14159265359 * (db->an_x) / 180;
}

int 	key_hook(int keycode, t_db *db)
{

	if (keycode == 53)
	{
		mlx_destroy_window(db->mlx_ptr, db->win_ptr);
		exit(0);
	}
	else if (keycode > 0 && keycode < 80 )
	{
		key_hook_rot(db, keycode);
	}
	mlx_clear_window(db->mlx_ptr, db->win_ptr);
}

int		main(int argc, char **argv)
{
	t_db db; // check if only 1 point
//	void	*mlx_ptr;
//	void	*win_ptr;

//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 500,500, "mlx 42");


	ft_init(&db);
	if (argc != 2)
		ft_error("argc!=2");
	ft_check_map(&db, argv[1]);
	ft_save_map(&db, argv[1]);
	int x = 0;
	int y = 0;

//		mlx_pixel_put(mlx_ptr, win_ptr, db.arr[0][0].x, db.arr[0][0].y, 0xffffff);


//	mlx_expose_hook(db.win_ptr, expose_hook, o);
	mlx_hook(db.win_ptr, 2, 0, key_hook, &db);
//	mlx_loop(db.mlx_ptr);
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
	while (y < db.y_counter - 1)
	{
		while (x < db.x_counter - 1)
		{
			db.color = (db.arr[y][x].z > 0) ? 0x0000ff : 0xffffff;
//			mlx_pixel_put(db.mlx_ptr, db.win_ptr, db.arr[y][x].x * db.scale,
//					db.arr[y][x].y * db.scale, db.color);
			line(&db, x, x + 1, y, y + 1, db.color );
			++x;
		}
		x = 0 ;
		++y;
	}

	mlx_loop(db.mlx_ptr);
	exit(0);
}