/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_ascending.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 13:33:58 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/07 22:09:22 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int			get_val_index(t_list *stack, int index)
{
	while (stack->content_size != index)
		stack = stack->next;
	return (*(int*)stack->content);
}

size_t		get_max_index(t_list *stack, int size)
{
	size_t	index;

	index = 0;
	while (stack)
	{
		if (index < stack->content_size)
			index = stack->content_size;
		stack = stack->next;
	}
	return (index);
}

int			get_pos(t_list *stack, int index)
{
	int		pos;

	pos = 0;
	if (index > 0)
		while (stack && ++pos && stack->content_size != index)
			stack = stack->next;
	return (pos);
}

void		in_ascending(t_list **stack, t_list **ins, int size)
{
	size_t	wall;
	size_t	curr;

	wall = get_max_index(*stack, size) - 1;
	curr = wall - 1;
	if (!*stack)
		return ;
	while (!stack_ascending(*stack, size))
		if (get_pos(*stack, curr) < get_pos(*stack, wall))
		{
			while (!stack_ascending(*stack, get_pos(*stack, wall)))
				if ((*stack)->content_size > ((*stack)->next)->content_size)
					ins_swap(ins, stack, 0, "sa");
				else
					ins_rotate(ins, stack, 0, "ra");
			curr--;
		}
		else
		{
			ins_rev_rotate(ins, stack, 0, "rra");
			if ((*stack)->content_size > ((*stack)->next)->content_size)
				ins_swap(ins, stack, 0, "sa");
		}
}
