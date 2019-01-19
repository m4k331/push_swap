/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 18:57:28 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/19 21:55:47 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
** Creating new empty stack (single linked list)
*/

t_list		*create_stack(int size)
{
	int		count;
	t_list	*head;
	t_list	*iter;

	count = 0;
	if (!(count++ < size && (head = ft_lstnew(0, 0))))
		return (0);
	iter = head;
	while (count < size)
		if ((iter->next = ft_lstnew(0, 0)) && ++count)
			iter = iter->next;
		else
			break ;
	if (count != size)
		while (head)
		{
			iter = head->next;
			free(head);
			head = iter;
		}
	return (head);
}
