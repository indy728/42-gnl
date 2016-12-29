/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:21:17 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/29 11:59:21 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*set_heap_buf(void)
{
	char *buf;

	buf = (char *)malloc(BUFF_SIZE + 1);
	bzero(buf, BUFF_SIZE + 1);
	return (buf);
}*/

int	get_next_line(const int fd, char **line)
{
	int		bytes_read;
	char	buf[BUFF_SIZE + 1];
	int 	i = 0;
	int  j = 0;
	static char	*dup;

//	printf("!1%s!\n", dup);
	bzero(buf, BUFF_SIZE + 1);
	bzero(line[0], strlen(line[0]));
	if (dup != NULL)
	{
		while (dup[j] && dup[j] != '\n')
		{
			line[0][j] = dup[j];
			j++;
		}
	}
	while ((bytes_read = read(fd, buf + i, BUFF_SIZE - i)))
	{
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				dup = strdup(buf + i + 1);
//				printf("!2%s!\n", dup);
				return (1);
			}
			line[0][j] = buf[i];
			j++;
			i++;
		}
		i = 0;
	}
	return (0);
}
