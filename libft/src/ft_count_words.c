/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 04:57:48 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/09 04:58:27 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	if (str[0] != c && str[0] != '\0')
		count++;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}
