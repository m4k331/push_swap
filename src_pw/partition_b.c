/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:57:36 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 10:49:54 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Checking the stack contents for values that are less or equal than the median
*/

static int			elems_less_eql_median(t_list *stack, int median, int size)
{
	while (stack && size--)
	{
		if (stack->content_size <= (size_t)median)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/*
** Fix sorted items on stack
*/

static inline void	fix_target_elem(t_ps *ps, int *put, int *size)
{
	(*put)++;
	(*size)--;
	ps->err = ins_put(ps, "pa");
	while (ps->err && (ps->a->content_size == ps->index || \
						(ps->a->next)->content_size == ps->index))
	{
		if ((ps->a->next)->content_size == ps->index)
			ps->err = ins_swap(ps, "sa");
		else
		{
			(*put)--;
			ps->index++;
			ps->err = ins_rotate(ps, "ra");
		}
	}
}

/*
** Splits the stack b in the median into halves,
** half in which less than the median is pushed onto the stack a.
** In case error returns -1.
*/

int					partition_b(t_ps *ps, int size)
{
	int				put;
	int				rot;
	int				median;

	rot = 0;
	median = get_median(ps->b, size);
	if ((put = 0) || !ps->a || !size)
		return (0);
	while (ps->err && (elems_less_eql_median(ps->b, median, size)))
		if (ps->b->content_size <= (size_t)median)
			fix_target_elem(ps, &put, &size);
		else if (++rot)
			ps->err = ins_rotate(ps, "rb");
	if (!ps->err)
		return (-1);
	if (ft_lstsize(ps->b) != (size_t)rot)
		while (ps->err && rot--)
			ps->err = ins_rev_rotate(ps, "rrb");
	if (put > 0)
		partition_b(ps, partition_a(ps, put));
	if (size > 0)
		partition_b(ps, size);
	return (size);
}
