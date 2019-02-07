/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:56:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/07 14:15:44 by ahugh            ###   ########.fr       */
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

void		partition(t_list **a, t_list **b, t_list **ins, int part)
{
	int		index;
	int		iter;
	int		wall;

	index = 0;
	iter = 0;
	wall = 0;
	while (*a && (index += part))
	{
		if ((iter = ft_lstsize(*a)) <= part)
		{
			if (iter < 6)
				bt_ascending(a, ins, iter);
			else
				in_ascending(a, ins, iter);
			break ;
		}
		wall = get_val_index(*a, index);
		while (*a && iter--)
			if (wall >= *(int*)(*a)->content)
				ins_put(ins, a, b, "pb");
			else
				ins_rotate(ins, a, b, "ra");
	}
}
