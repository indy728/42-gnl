/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:11:39 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/09 04:49:07 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *str)
{
	size_t	i;
	size_t	j;
	size_t	ws;
	char	*trim;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	ws = ft_count_whitespaces(str);
	trim = (char *)malloc(ft_strlen(str) - ws + 1);
	if (!trim)
		return (NULL);
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
		i++;
	while (j < ft_strlen(str) - ws)
	{
		trim[j] = str[i];
		i++;
		j++;
	}
	trim[j] = '\0';
	return (trim);
}
