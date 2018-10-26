/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 21:31:56 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/26 19:40:25 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_save_map(t_db *db)
{
	size_t line_len;
	size_t i;
	t_p *temp_point;
	t_p *prev_point;

	i = 0;
	prev_point = NULL;
	line_len = (size_t)ft_strlen(db->line);
	while (i < line_len)
	{
		if (db->line[i] == ',')
			ft_parse_hex();  //make this!
		if (ft_isalpha(db->line[i]))
			ft_error("not a map\n");
		else if (ft_isdigit(db->line[i]))
		{
			temp_point = db->point;
			while (temp_point != NULL) //add last one point
			{
				prev_point = temp_point;
				temp_point = temp_point->next;
			}
			temp_point = ft_memalloc(sizeof(t_p));
			temp_point->z = ft_atoi(&db->line[i]);
			temp_point->x = db->x_counter++;
			temp_point->y = db->y_counter;
			if (!db->point)
				db->point = temp_point;
			else if (prev_point)
				prev_point->next = temp_point;
		}
		i += ft_nbr_lngth(temp_point->z) ? ft_nbr_lngth(temp_point->z) : 1;
	}
	if (db->x_4cpmr == 0)
	{
		db->x_4cpmr = db->x_counter;
	}
	else if (db->x_4cpmr != db->x_counter)
	{
		ft_error("wrong quantity of xs");
	}
	db->x_counter = 0;
	++db->y_counter;
}

int		main(int argc, char **argv)
{
	t_db db; // check if only 1 point

	ft_init(&db);
	if (argc < 2)
		ft_error("argc<2");
	if ((db.fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("can't read");
	while (get_next_line(db.fd, &db.line) > 0)
	{
		//check for null
		ft_save_map(&db);
	}
	int y = 0;
	int x = 0;
	while (y < db.y_counter){
		while (x < db.x_4cpmr){
			ft_printf("%l",db.point->z);
			++x;
		}
		x = 0;
		y ++;
	}

	return 0;
}