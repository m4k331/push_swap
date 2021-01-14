/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:49:25 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 15:58:07 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** functions return 1 if stack is sorted, otherwise 0.
*/

int			stack_ascending(t_list *stack, int size)
{
	int		ascending;
	t_list	*previous;

	ascending = 1;
	previous = stack;
	if (!stack || !size)
		return (ascending);
	while (stack->next && --size > 0)
	{
		stack = stack->next;
		if (previous->content_size != stack->content_size - 1)
		{
			ascending = 0;
			break ;
		}
		previous = stack;
	}
	return (ascending);
}

int			stack_descending(t_list *stack, int size)
{
	int		descending;
	t_list	*previous;

	descending = 1;
	previous = stack;
	if (!stack || !size)
		return (descending);
	while (stack->next && --size > 0)
	{
		stack = stack->next;
		if (previous->content_size != stack->content_size + 1)
		{
			descending = 0;
			break ;
		}
		previous = stack;
	}
	return (descending);
}
