/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:59:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 10:49:28 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Check the stack contents for values that are greater or equal than the median
*/

static int			elems_more_eql_median(t_list *stack, int median, int size)
{
	while (stack && size--)
	{
		if (stack->content_size >= (size_t)median)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/*
** Support function pushing elems in stack B
*/

static inline void	pushing_in_stack_b(t_ps *ps, int *put, int *size)
{
	if (ft_lstlast(ps->a)->content_size == ps->index - 1 \
			&& (ps->a->content_size == ps->index || \
				(ps->a->next)->content_size == ps->index))
	{
		if ((ps->a->next)->content_size == ps->index)
			ps->err = ins_swap(ps, "sa");
		ps->index++;
		ps->err = ins_rotate(ps, "ra");
	}
	else
	{
		(*put)++;
		ps->err = ins_put(ps, "pb");
	}
	(*size)--;
}

/*
** Support function rotating elems in stack A
*/

static inline void	rotate_in_stack_a(t_ps *ps, int *rot, int *size)
{
	if (ft_lstlast(ps->a)->content_size == ps->index - 1\
			&& (ps->a->content_size == ps->index || \
				(ps->a->next)->content_size == ps->index))
	{
		if ((ps->a->next)->content_size == ps->index)
			ps->err = ins_swap(ps, "sa");
		(*size)--;
		ps->index++;
	}
	else
		(*rot)++;
	ps->err = ins_rotate(ps, "ra");
}

/*
** Splits the stack a in the median into halves,
** half in which less than the median is pushed onto the stack b.
** In case error returns -1.
*/

int					partition_a(t_ps *ps, int size)
{
	int				rot;
	int				put;
	int				median;

	rot = 0;
	put = 0;
	median = get_median(ps->a, size);
	if (!ps->a || !(size > 0))
		return (0);
	while (ps->err && (elems_more_eql_median(ps->a, median, size - rot)))
		if (ps->a->content_size < (size_t)median)
			rotate_in_stack_a(ps, &rot, &size);
		else
			pushing_in_stack_b(ps, &put, &size);
	while (ps->err && rot--)
		ps->err = ins_rev_rotate(ps, "rra");
	if (!ps->err)
		return (-1);
	if (size > 0)
		put += partition_a(ps, size);
	return (put);
}
