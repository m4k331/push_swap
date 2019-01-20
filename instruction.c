/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 13:29:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/20 16:02:12 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
** Swap the first 2 elements in stack
*/

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

/*
** Take the first element stack src and put it at the top of dst
*/

void		put_stack(t_list **dst, t_list **src)
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

/*
** Shift up all elements of stack by 1 (the first element becomes the last one)
*/

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

/*
** Shift down all elements of stack by 1 (the last element becomes the 1-st one)
*/

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
