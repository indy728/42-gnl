/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:23:59 by kmurray           #+#    #+#             */
/*   Updated: 2016/11/29 15:05:23 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	whitespace(char const *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int			ft_atoi(char const *str)
{
	int i;
	int a;
	int flag;

	flag = 1;
	a = 0;
	i = whitespace(str);
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = a * 10 + (str[i] - '0');
		i++;
	}
	return (flag * a);
}
