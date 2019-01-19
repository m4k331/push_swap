/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:29:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/19 13:29:18 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		swap_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = 0;
	if (stack && *stack && (*stack)->next)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
}

void		push_stack(t_list **dst, t_list **src)
{
	t_list	*tmp;

	tmp = 0;
	if (dst && src && *dst && *src)
	{
		tmp = *src;
		*src = (*src)->next;
		tmp->next = *dst;
		*dst = tmp;
	}
}

void		rotate_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*iter;

	tmp = 0;
	iter = 0;
	if (stack && *stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		iter = *stack;
		while (iter->next)
			iter = iter->next;
		iter->next = tmp;
		tmp->next = 0;
	}
}

void		rev_rotate_stack(t_list **stack)
{
	t_list	*last;
	t_list	*iter;

	last = 0;
	iter = 0;
	if (stack && *stack && (*stack)->next)
	{
		iter = *stack;
		while ((iter->next)->next)
			iter = iter->next;
		last = iter->next;
		last->next = *stack;
		*stack = last;
		iter->next = 0;
	}
}
