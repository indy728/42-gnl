/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:07:46 by kmurray           #+#    #+#             */
/*   Updated: 2016/12/08 22:34:28 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*temp;

	if (*alst)
	{
		head = *alst;
		while (head->next != NULL)
		{
			temp = head->next;
			del(head->content, head->content_size);
			free(head);
			head = temp;
		}
		del(head->content, head->content_size);
		free(head);
		*alst = NULL;
	}
}
