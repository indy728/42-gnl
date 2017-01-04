/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:04:58 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/06 15:54:20 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *str, char (*f)(char))
{
	size_t	i;
	char	*dup;

	i = 0;
	if (str)
	{
		dup = ft_strdup(str);
		if (!dup)
			return (NULL);
		while (dup[i])
		{
			dup[i] = f(dup[i]);
			i++;
		}
		return (dup);
	}
	return (NULL);
}
