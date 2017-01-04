/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:49:21 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/02 18:08:29 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(ft_strlen(str) + 1);
	if (!dup || str == NULL)
		return (NULL);
	while (i < ft_strlen(str))
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
