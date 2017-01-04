/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 04:41:23 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/09 05:01:36 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_whitespaces(char const *str)
{
	size_t i;
	size_t ws;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	ws = i;
	i = ft_strlen(str) - 1;
	if (ws != ft_strlen(str))
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		{
			i--;
			ws++;
		}
	}
	return (ws);
}
