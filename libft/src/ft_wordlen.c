/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 04:54:35 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/09 04:57:34 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordlen(char const *str, char c, size_t i)
{
	size_t	count;

	count = 0;
	while (str[i] && str[i] != c)
	{
		i++;
		count++;
	}
	return (count);
}
