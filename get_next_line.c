/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:21:17 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/08 14:05:47 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	int		bytes_read;
	char	buf[BUFF_SIZE + 1];
	int 	i = 0;
	int		j = 0;
	static char	*dup;
	char *ptr = *line;

	ft_bzero(buf, BUFF_SIZE + 1);
	if (dup != NULL)
	{
		while (dup[j])
		{
			if (dup[j] == '\n')
			{
				dup = dup + j + 1;
				return (1);
			}
			ft_bzero(ptr + j, ft_strlen(dup));
			ptr[j] = dup[j];
			j++;
		}
	}
	while ((bytes_read = read(fd, buf, BUFF_SIZE)))
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				dup = ft_strdup(buf + i + 1);
				return (1);
			}
			ft_bzero(ptr + j, BUFF_SIZE + 1);
			ptr[j] = buf[i];
			j++;
			i++;
		}
		i = 0;
	}
	return (0);
}
