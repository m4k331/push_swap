/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:11:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/02 10:48:38 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** Function depending on the instruction number applies them
*/

static int		apply_ins(t_ps *ps, int index)
{
	if (ps->a)
	{
		if (index == 0)
			ps->err = ins_swap(ps, "sa");
		else if (index == 1)
			ps->err = ins_rotate(ps, "ra");
		else if (index == 2)
			ps->err = ins_rev_rotate(ps, "rra");
	}
	return (ps->err);
}

/*
** Undoes and removes the last instruction in the stack
*/

static void		cancel_ins(t_ps *ps)
{
	if (ps->ins)
	{
		if (*(char*)ps->ins->content == 's')
			swap_stack(&ps->a);
		else if (*((char*)ps->ins->content + 1) == 'a')
			rev_rotate_stack(&ps->a);
		else
			rotate_stack(&ps->a);
		ft_lstdelnbr(&ps->ins, del_content, 0);
	}
}

/*
** Implements the Back Tracking algorithm for sorting stack A
*/

static int		bt(t_ps *ps, size_t size, int iter)
{
	int			index;

	index = 0;
	if (stack_ascending(ps->a, size))
		return (1);
	while (iter && index < 3)
	{
		if (!(apply_ins(ps, index)))
			return (0);
		if (bt(ps, size, iter - 1))
			return (1);
		else
			cancel_ins(ps);
		index++;
	}
	return (0);
}

/*
**  Sorts stack A, on success returns 0, otherwise -1
*/

int				bt_sort(t_ps *ps, size_t size)
{
	int			iter;

	iter = 1;
	while (!bt(ps, size, iter++))
		if (!ps->err)
			break ;
	ps->index = size + 1;
	return ((ps->err ? 0 : -1));
}
