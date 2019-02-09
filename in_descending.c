/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_descending.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:18:18 by ahugh             #+#    #+#             */
/*   Updated: 2019/02/09 19:34:01 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		in_descending(t_list **a, t_list **b,  t_list **ins, int size)
{
	int		max;

	max = *b ? get_max_index(*b, size) : 0;
	if (max)
	{
		while (!stack_descending(*b, size))
			if (size < 4)
				bt_descending(b, ins, size);
			else if (max == (*b)->content_size)
			{
				ins_put(ins, a, b, "pa");
				size--;
				max = get_max_index(*b, size);
			}
			else
			{
				if (get_pos(*b, get_max_index(*b, size)) > (size / 2))
					ins_rev_rotate(ins, a, b, "rrb");
				else
					ins_rotate(ins, a, b, "rb");
			}
		while (size--)
			ins_put(ins, a, b, "pa");
	}
}
