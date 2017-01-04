/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:38:00 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/08 23:29:03 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *scout;

	if (lst && f)
	{
		scout = lst;
		while (scout->next != NULL)
		{
			f(scout);
			scout = scout->next;
		}
		f(scout);
	}
}
