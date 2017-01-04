/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:57:07 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/08 01:09:37 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 && s2)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
			i++;
		if (s1[i] - s2[i] == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
