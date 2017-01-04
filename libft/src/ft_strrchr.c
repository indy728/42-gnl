/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:31:00 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/06 22:53:54 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	int		i;
	char	*s1;

	s1 = (char *)str;
	i = ft_strlen(s1);
	while (i >= 0)
	{
		if (s1[i] == c)
			return (s1 + i);
		i--;
	}
	return (NULL);
}
