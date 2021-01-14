/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:15:12 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 10:50:21 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Check the stack contents for values that are greater than the median
*/

static int	elems_more_median(t_list *stack, int median, int size)
{
	while (stack && size--)
	{
		if (stack->content_size > (size_t)median)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/*
** Sorts stack A by selecting an algorithm depending on the size of the stack.
** When the size is 5 or less, the BRUTFORCE algorithm is used.
** For larger sizes, an improved QUICK SORT algorithm is used.
** Function in case success returns 0, otherwise -1
*/

int			sort(t_ps *ps, int size)
{
	int		put;
	int		median;

	put = 0;
	median = get_median(ps->a, size);
	if (size < 7)
		return (bt_sort(ps, size));
	if (!ps->a || !size)
		return (0);
	while (ps->err && elems_more_median(ps->a, median, size - put))
		if (ps->a->content_size <= (size_t)median)
			ps->err = ins_rotate(ps, "ra");
		else
		{
			put++;
			ps->err = ins_put(ps, "pb");
		}
	if (!ps->err)
		return (-1);
	sort(ps, size - put);
	partition_b(ps, put);
	return (0);
}
