/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:21:17 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/07 13:46:20 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_bytes(int fd, int j, char *dup, char *ptr)
{
	int		i;
	int		bytes_read;
	char	buf[BUFF_SIZE + 1];

	i = 0;
	ft_bzero(buf, BUFF_SIZE + 1);
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

int			get_next_line(const int fd, char **line)
{
	int			j;
	static char	*dup;
	char		*ptr;

	j = 0;
	ptr = *line;
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
	if (read_bytes(fd, j, dup, ptr))
		return (1);
	return (0);
}
