/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:37:32 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 20:22:19 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*previous;

	previous = 0;
	if (alst && del)
	{
		while ((previous = *alst))
		{
			*alst = (*alst)->next;
			ft_lstdelone(&previous, del);
		}
		*alst = NULL;
	}
}
