/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:44:29 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/09 04:58:59 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	newstring(char const *str, char *new, size_t wl, size_t n)
{
	size_t	i;

	i = 0;
	while (i < wl)
	{
		new[i] = str[n];
		i++;
		n++;
	}
	new[i] = '\0';
}

char			**ft_strsplit(char const *str, char c)
{
	size_t	i;
	size_t	wl;
	size_t	n;
	char	**split;

	i = 0;
	n = 0;
	if (!str)
		return (NULL);
	split = (char **)malloc(sizeof(split) * ft_count_words(str, c) + 1);
	if (!split)
		return (NULL);
	while (i < ft_count_words(str, c))
	{
		while (str[n] == c)
			n++;
		wl = ft_wordlen(str, c, n);
		split[i] = (char *)malloc(wl + 1);
		newstring(str, split[i], wl, n);
		n = n + wl;
		i++;
	}
	split[i] = NULL;
	return (split);
}
