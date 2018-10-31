/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:05:18 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/31 21:10:18 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_parse_hex(t_db *db, int i)
{
	int j;

	j = 0;
	++i;
	if (db->line[i] == '0')
	{
		++i;
		if (db->line[i] == 'x')
		{
			++i;
			while (ft_isalnum(db->line[i]) && j < 6)
				++i && ++j;
		}
		else
			ft_error("not valid map\n");
	}
	else
		ft_error("not valid map\n");
	return (9);
}

void	ft_check_map(t_db *db, char *file)
{
	int i;

	if ((db->fd = open(file, O_RDONLY)) < 0)
		ft_error("can't read");
	while ((i = get_next_line(db->fd, &db->line)) > 0)
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

void	ft_inner_cycle(t_db *db, long i, int y, int x)
{
	while (i < ft_strlen(db->line))
	{
		if (ft_isdigit(db->line[i]))
		{
			db->arr[y][x].z = ft_atoi(&db->line[i]);
			db->arr[y][x].x = x;
			db->arr[y][x].y = y;
			db->arr[y][x].z_copy = db->arr[y][x].z;
			db->arr[y][x].x_copy = x;
			db->arr[y][x++].y_copy = y;
			while (i < ft_strlen(db->line) && db->line[i] != ' ' &&
			db->line[i] != ',')
				++i;
			if (db->line[i] == ',')
			{
				i += ft_parse_hex(db, i);
				if (db->line[i] != ' ')
					ft_error("not valid map\n");
			}
			continue ;
		}
		else if (db->line[i] != ' ' && db->line[i] != '-')
			ft_error("not a valid map\n");
		++i;
	}
}

void	ft_save_map(t_db *db, char *file)
{
	long	i;
	int		y;
	int		x;

	x = 0;
	y = 0;
	i = 0;
	if ((db->fd = open(file, O_RDONLY)) < 0)
		ft_error("can't read");
	db->arr = ft_memalloc(sizeof(t_p) * db->y_counter);
	while (get_next_line(db->fd, &db->line) > 0)
	{
		db->arr[y] = ft_memalloc(sizeof(t_p) * db->x_counter);
		ft_inner_cycle(db, 0, y, x);
		x = 0;
		i = 0;
		++y;
		free(db->line);
	}
	close(db->fd);
}
