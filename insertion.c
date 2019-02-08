/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 20:52:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/08 22:44:36 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	ft_left(t_list *stack, int index, int size)
{
	int		flag;

	flag = 0;
write(1, "LEFT\n", 5);
	while (size--)
	{
		if (stack->content_size == index && ++flag)
			break ;
		stack = stack->next;
	}
write(1, "__LEFT\n", 7);
	return (flag);
}

void		insertion(t_list **a, t_list **b, t_list **ins, int size)
{
	int		left;
	int		right;
	int		max;

	left = size;
	right = 0;
	if ((max = find_max_lr(*b, left, right)) && *a)
		while (!stack_descending(*b, left) || !stack_ascending(*b, right))
		{
			write(1, "I\n", 2);
			if (ft_left(*b, max, left))
				while ((*b)->content_size != max)
				{
					if ((*b)->content_size < ((*b)->next)->content_size)
						ins_swap(ins, a, b, "sb");
					else
					{
						ins_rotate(ins, a, b, "rb");
						right++;
					}
				}
			else
			{
				write(1, "RIGHT\n", 6);
				while ((*b)->content_size != max && ++left && right--)
					ins_rev_rotate(ins, a, b, "rrb");
			}
			ins_put(ins, a, b, "pa");
			left--;
			if (*b)
				max = find_max_lr(*b, left, right);
		}
}
