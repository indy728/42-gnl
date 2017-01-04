/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:07:07 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/11 01:55:46 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *str, unsigned int start, size_t size)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!str)
		return (NULL);
	if (start + size > ft_strlen(str))
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (size) + 1);
	if (!sub)
		return (NULL);
	while (i < size)
	{
		sub[i] = *(str + start + i);
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
