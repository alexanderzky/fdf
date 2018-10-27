/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:31:56 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/27 20:01:35 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "fdf.h"

void	ft_init(t_db *db)
{
	db->line = NULL;
	db->x_counter = 0;
	db->y_counter = 0;
	db->x_4cpmr = 0;
	db->point = NULL;
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
	size_t	i;
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
			if (ft_isalpha(db->line[i]))
				ft_error("not a valid map\n");
			else if (ft_isdigit(db->line[i]))
			{
//				db->arr[y] = ft_memalloc(sizeof(t_p) * db->x_counter);
				db->arr[y][x].z = (double)ft_atoi(&db->line[i]);
				db->arr[y][x].x = x;
				db->arr[y][x].y = y;
				db->arr[y][x].x_copy = x;
				db->arr[y][x].y_copy = y;
				db->arr[y][x].z_copy = db->arr[y][x].z;
				++x;
			}
			else if (db->line[i] == ',')
				ft_parse_hex();  //make this!
			i += ft_nbr_lngth((long)db->arr[y][x].z) ?
					ft_nbr_lngth((long)db->arr[y][x].z) : 1;
		}
		x = 0;
		i = 0;
		++y;


		free(db->line);
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


	return 0;
}