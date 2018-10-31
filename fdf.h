/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:33:07 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/31 20:56:26 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct		s_point
{
	double			x;
	double			y;
	double			z;
	long			color;
	double			x_copy;
	double			y_copy;
	double			z_copy;
}					t_p;

typedef struct		s_db
{
	int				fd;
	char			*line;
	size_t			x_counter;
	size_t			y_counter;
	struct s_point	**arr;
	int				scale;
	double			alp;
	double			bet;
	double			gam;
	int				color;
	int				an_z;
	int				an_y;
	int				an_x;
	void			*mlx_ptr;
	void			*win_ptr;
	int				size_x;
	int				size_y;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				y1;
}					t_db;

void				ft_init(t_db *db);
void				ft_error(char *str);
int					key_hook(int keycode, t_db *db);
void				ft_init_mlx(t_db *db);
int					ft_parse_hex(t_db *db, int i);
void				ft_check_map(t_db *db, char *file);
void				ft_save_map(t_db *db, char *file);
void				calc_mod1(t_db *db, int i, int z);
void				line(t_db *db, int x0, int x1, int y0);
void				ft_point(t_db *db);
#endif
