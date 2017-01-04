/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:06:17 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/01 14:51:46 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*bloc;

	bloc = (void *)malloc(size);
	if (!bloc)
		return (NULL);
	ft_bzero(bloc, size);
	return (bloc);
}
