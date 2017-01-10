/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:21:17 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/09 16:45:43 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			fd_lst_add(int fd, char *str, t_fd_list **begin_list)
{
	t_fd_list	*new;

	if (!(new = (t_fd_list *)malloc(sizeof(t_fd_list))))
		return (0);
	if (!(new->str = (char *)malloc(ft_strlen(str) + 1)))
	{
		free(new);
		return (0);
	}
	new->fd = fd;
	new->str = ft_strdup(str);
	new->next = *begin_list;
	*begin_list = new;
	return (1);
}

void		fd_lst_del(int fd, t_fd_list **begin_list)
{
	t_fd_list	*scout;
	t_fd_list	*trail;

	scout = *begin_list;
	while (scout->fd != fd)
	{
		trail = scout;
		scout = scout->next;
	}
	if (scout == *begin_list)
		*begin_list = scout->next;
	free(scout->str);
	free(scout);
}

int			check_fd_list(int fd, char **line, t_fd_list **begin_list)
{
	t_fd_list	*scout;
	int			i;

	scout = *begin_list;
	i = 0;
	while (scout->fd != fd && scout->next)
		scout = scout->next;
	if (scout->fd != fd)
		return (0);
	while (scout->str[i])
	{
		if (scout->str[i] == '\n')
		{
			scout->str = ft_strdup(scout->str + i + 1);
			return (1);
		}
		i++;
	}
	*line = strndup(scout->str, i);
	fd_lst_del(fd, begin_list);
	return (0);
}

int			read_file(int fd, char **line, t_fd_list **begin_list)
{
	int		bytes_read;
	char	buf[BUFF_SIZE + 1];
	int		i;

	ft_bzero(buf, BUFF_SIZE + 1);
	while ((bytes_read = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		if (bytes_read == -1)
			return (-1);
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				if (!(fd_lst_add(fd, buf + i + 1, begin_list)))
					return (-1);
				return (1);
			}
			i++;
		}
		*line = strndup(buf, i);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd_list	*begin_list = NULL;

	if (begin_list != NULL)
	{
		if (check_fd_list(fd, line, &begin_list))
			return (1);
	}
	if (read_file(fd, line, &begin_list) > 0)
		return (1);
	else if (read_file(fd, line, &begin_list) < 0)
		return (-1);
	return (0);
}
