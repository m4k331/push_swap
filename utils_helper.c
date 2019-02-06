/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:56:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/06 13:36:34 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
		if (*(int*)previous->content > *(int*)stack->content)
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
		if (*(int*)previous->content < *(int*)stack->content)
		{
			descending = 0;
			break ;
		}
		previous = stack;
	}
	return (descending);
}
