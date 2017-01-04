/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:35:05 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/21 11:41:33 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*make_str(char *ascii, int cb, int n, int base)
{
	unsigned int	o;

	if (n < 0)
	{
		o = n * -1;
		if (base == 10)
			ascii[0] = '-';
	}
	else
		o = n;
	while (o / base != 0)
	{
		ascii[--cb] = ft_base_char(o % base);
		o = o / base;
	}
	ascii[--cb] = ft_base_char(o % base);
	return (ascii);
}

char			*ft_itoa_base(int n, int base)
{
	char			*ascii;
	int				cb;

	if (base > 16 || base < 2)
		return (NULL);
	cb = ft_count_base(n, base);
	ascii = (char *)malloc(cb + 1);
	if (!ascii)
		return (NULL);
	ascii[cb] = '\0';
	return (make_str(ascii, cb, n, base));
}
