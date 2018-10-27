/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozalisky <ozalisky@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:06:25 by ozalisky          #+#    #+#             */
/*   Updated: 2018/10/27 19:27:13 by ozalisky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_gnl	*ft_check_fd(int fd, t_gnl **slist)
{
	t_gnl	*newlist;
	t_gnl	*temp;

	temp = *slist;
	while (temp != NULL)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	newlist = ft_memalloc(sizeof(struct s_gnl));
	newlist->fd = fd;
	newlist->file_size = 0;
	newlist->buffer = NULL;
	newlist->next = NULL;
	newlist->next = *slist;
	*slist = newlist;
	return (newlist);
}

char	*ft_sncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int		ft_find_n(char **line, t_gnl **list, char *pos)
{
	size_t		line_size;
	char		*local_buff;

	line_size = (pos - (*list)->buffer);
	if (!(*line = malloc(line_size + 1)))
		return (-1);
	ft_sncpy(*line, (*list)->buffer, line_size);
	(*line)[line_size] = '\0';
	(*list)->file_size -= (line_size + 1);
	if ((*list)->file_size != 0)
	{
		if (!(local_buff = malloc((*list)->file_size + 1)))
			return (-1);
		ft_sncpy(local_buff, (*list)->buffer + line_size + 1,
			(*list)->file_size);
		free((*list)->buffer);
		(*list)->buffer = local_buff;
		local_buff[(*list)->file_size] = '\0';
	}
	else
	{
		free((*list)->buffer);
		(*list)->buffer = NULL;
	}
	return (1);
}

int		ft_read(int fd, t_gnl **list)
{
	ssize_t		rd;
	char		*temp;

	if (!(*list)->buffer)
		(*list)->buffer = malloc(BUFF_SIZE);
	if (!(temp = ft_memalloc(BUFF_SIZE + (*list)->file_size + 1)))
		return (-1);
	if ((*list)->file_size > 0)
		ft_sncpy(temp, (*list)->buffer, (*list)->file_size);
	free((*list)->buffer);
	(*list)->buffer = temp;
	if ((rd = read(fd, temp + (*list)->file_size, BUFF_SIZE)) < 0)
		return (-1);
	(*list)->file_size += rd;
	temp[(*list)->file_size] = '\0';
	return (int)(rd > 0 ? 1 : rd);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*slist;
	t_gnl			*clist;
	int				rd;
	char			*pos;

	if (fd < 0 || !line || BUFF_SIZE < 1 || !(clist = ft_check_fd(fd, &slist)))
		return (-1);
	*line = 0;
	if ((pos = ft_memchr(clist->buffer, '\n', clist->file_size)))
		return (ft_find_n(line, &clist, pos));
	while ((rd = ft_read(fd, &clist)) > 0)
		if ((pos = ft_memchr(clist->buffer, '\n', clist->file_size)))
			return (ft_find_n(line, &clist, pos));
	if (rd < 0)
		return (-1);
	if (rd == 0 && clist->file_size == 0)
	{
		ft_strdel(line);
		return (rd);
	}
	*line = ft_strsub(clist->buffer, 0, clist->file_size + 1);
	free(clist->buffer);
	clist->buffer = NULL;
	clist->file_size = 0;
	return (1);
}
