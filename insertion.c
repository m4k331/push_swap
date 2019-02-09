/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:52:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/09 19:47:48 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	get_max(t_list *stack, int left, int right)
{
	int		max;

	max = 0;
	if (!stack)
		return (0);
	if (left && (max = stack->content_size))
		while (left--)
		{
			if (max < stack->content_size)
				max = stack->content_size;
			stack = stack->next;
		}
	if (right && (stack = ft_lstat(stack, ft_lstsize(stack) - right)))
	{
		max = max ? max : stack->content_size;
		while (stack)
		{
			if (max < stack->content_size)
				max = stack->content_size;
			stack = stack->next;
		}
	}
	return (max);
}

static int	ft_left(t_list *stack, int index, int size)
{
	int		flag;

	flag = 0;
	while (size--)
	{
		if (stack->content_size == index && ++flag)
			break ;
		stack = stack->next;
	}
	return (flag);
}

void		in_mid(t_list **a, t_list **b, t_list **ins, int size)
{
	int		left;
	int		right;
	int		max;

	left = size;
	right = 0;
	if ((max = get_max(*b, left, right)))
		while (left || right)
		{
			if (ft_left(*b, max, left))
				while ((*b)->content_size != max)
				{
					if (((*b)->next)->content_size == max)
						ins_swap(ins, a, b, "sb");
					else if (left-- && ++right)
						ins_rotate(ins, a, b, "rb");
				}
			else
				while ((*b)->content_size != max && ++left && right--)
					ins_rev_rotate(ins, a, b, "rrb");
			ins_put(ins, a, b, "pa");
			max = (*b && (--left || right)) ? get_max(*b, left, right) : 0;
		}
}
