/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 15:49:26 by ahugh             #+#    #+#             */
/*   Updated: 2019/01/31 16:30:33 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
** The function of swap for stacks
** returns 1 if successfully, or 0 if not.
** inst: sa, sb, ss
** NOT PROTECTED
*/

int			wrap_swap(t_list **a, t_list **b, char *inst)
{
	int		swap;

	swap = 1;
	if (inst[0] == 's')
	{
		if (inst[1] == 's')
		{
			swap_stack(a);
			swap_stack(b);
		}
		else if (inst[1] == 'a')
			swap_stack(a);
		else if (inst[1] == 'b')
			swap_stack(b);
		else
			swap = 0;
	}
	return (swap);
}

/*
** The function of put elems for stacks
** returns 1 if successfully, or 0 if not.
** inst: pa, pb
** NOT PROTECTED
*/

int			wrap_put(t_list **a, t_list **b, char *inst)
{
	int		put;

	put = 1;
	if (inst[0] == 'p')
	{
		if (inst[1] == 'a')
			put_stack(a, b);
		else if (inst[1] == 'b')
			put_stack(b, a);
		else
			put = 0;
	}
	return (put);
}

/*
** The function of rotate elems for stacks
** returns 1 if successfully, or 0 if not.
** inst: ra, rb, rr
** NOT PROTECTED
*/

int			wrap_rotate(t_list **a, t_list **b, char *inst)
{
	int		rotate;

	rotate = 1;
	if (inst[0] == 'r')
	{
		if (inst[1] == 'r')
		{
			rotate_stack(a);
			rotate_stack(b);
		}
		else if (inst[1] == 'a')
			rotate_stack(a);
		else if (inst[1] == 'b')
			rotate_stack(b);
		else
			rotate = 0;
	}
	return (rotate);
}

/*
** The function of reverse rotate elems for stacks
** returns 1 if successfully, or 0 if not.
** inst: rra, rrb, rrr
** NOT PROTECTED
*/

int			wrap_rev_rotate(t_list **a, t_list **b, char *inst)
{
	int		rev_rotate;

	rev_rotate = 1;
	if (inst[0] == 'r' && inst[1] == 'r')
	{
		if (inst[2] == 'r')
		{
			rev_rotate_stack(a);
			rev_rotate_stack(b);
		}
		else if (inst[2] == 'a')
			rev_rotate_stack(a);
		else if (inst[2] == 'b')
			rev_rotate_stack(b);
		else
			rev_rotate = 0;
	}
	return (rev_rotate);
}
