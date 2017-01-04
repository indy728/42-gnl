/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:30:56 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/09 18:34:29 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	size_t			i;
	unsigned int	o;
	char			*ascii;

	ascii = (char *)malloc(ft_count_base(n, 10) + 1);
	if (!ascii)
		return (NULL);
	i = ft_count_base(n, 10);
	ascii[i] = '\0';
	i--;
	if (n < 0)
	{
		o = n * -1;
		ascii[0] = '-';
	}
	else
		o = n;
	while (o / 10 != 0)
	{
		ascii[i] = o % 10 + '0';
		o = o / 10;
		i--;
	}
	ascii[i] = o % 10 + '0';
	return (ascii);
}
