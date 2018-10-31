/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:02:33 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/31 21:00:01 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_mod1(t_db *db, int i, int z)
{
	(db->arr[i][z]).y = ((db->arr[i][z]).y_copy * (sin(db->alp) *
			cos(db->gam) + cos(db->alp) * cos(db->bet) * sin(db->gam)) +
					(db->arr[i][z]).y_copy * (cos(db->alp) * cos(db->bet) *
					cos(db->gam) - sin(db->alp) * sin(db->gam)) -
					(db->arr[i][z]).z * cos(db->alp) * sin(db->bet)) +
							(db->size_y) / 20 - ((int)db->y_counter / 2);
}

void	ft_init(t_db *db)
{
	db->line = NULL;
	db->x_counter = 0;
	db->y_counter = 0;
	db->scale = 10;
	db->an_z = 10;
	db->an_x = 12;
	db->an_y = 7;
	db->size_x = 1000;
	db->size_y = 1000;
	db->color = 0xffffff;
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int		key_hook(int keycode, t_db *db)
{
	if (keycode == 53)
	{
		mlx_destroy_window(db->mlx_ptr, db->win_ptr);
		exit(0);
	}
	return (1);
}

void	ft_init_mlx(t_db *db)
{
	if (db->x_counter == 50 && db->y_counter == 50)
	{
		db->size_x = 1000;
		db->size_y = 1000;
	}
	else if (db->x_counter <= 60 && db->y_counter <= 60)
	{
		db->size_x = 500;
		db->size_y = 600;
	}
	else if (db->x_counter <= 100 && db->y_counter <= 100)
	{
		db->size_x = 1920;
		db->size_y = 1080;
		db->scale = 5;
	}
	else if (db->x_counter <= 200 && db->y_counter <= 200)
	{
		db->size_x = 1920;
		db->size_y = 1080;
		db->scale = 2;
	}
	db->mlx_ptr = mlx_init();
	db->win_ptr = mlx_new_window(db->mlx_ptr, db->size_x, db->size_y, "mlx 42");
}
