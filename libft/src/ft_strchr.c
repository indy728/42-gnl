/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:53:55 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/07 01:56:41 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int c)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *)str;
	while (s1[i])
	{
		if (s1[i] == c)
			return (s1 + i);
		i++;
	}
	if (s1[i] == c)
		return (s1 + i);
	return (NULL);
}
