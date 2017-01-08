/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:08:00 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/08 14:12:44 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/includes/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>///////////////////////////////////////////////////////////////////////
# include <string.h>////////////////////////////////////////////////////////////////////

# define BUFF_SIZE 5

typedef struct		s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}					t_list;

int	get_next_line(const int fd, char **line);

#endif
