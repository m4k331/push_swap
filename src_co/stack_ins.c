/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:29:15 by ahugh             #+#    #+#             */
/*   Updated: 2019/04/01 17:51:51 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

/*
** functions return 1 if successful, otherwise 0.
** 'in' accepts instructions from the patterns:
** "sa", "sb", "ss", "ra", "rb", "rr", "pa", "pb", "rra", "rrb", "rrr".
*/

int			ins_swap(t_ps *ps, char *in)
{
	t_list	*new;

	new = 0;
	if (in[0] == 's')
	{
		if (in[1] == 'a' || in[1] == 's')
			swap_stack(&ps->a);
		if (in[1] == 'b' || in[1] == 's')
			swap_stack(&ps->b);
		if ((new = ft_lstnew(in, 3)))
			ft_lstadd(&ps->ins, new);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int			ins_put(t_ps *ps, char *in)
{
	t_list	*new;

	new = 0;
	if (in[0] == 'p')
	{
		if (in[1] == 'a')
			put_stack(&ps->a, &ps->b);
		if (in[1] == 'b')
			put_stack(&ps->b, &ps->a);
		if ((new = ft_lstnew(in, 3)))
			ft_lstadd(&ps->ins, new);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int			ins_rotate(t_ps *ps, char *in)
{
	t_list	*new;

	new = 0;
	if (in[0] == 'r')
	{
		if (in[1] == 'a' || in[1] == 'r')
			rotate_stack(&ps->a);
		if (in[1] == 'b' || in[1] == 'r')
			rotate_stack(&ps->b);
		if ((new = ft_lstnew(in, 3)))
			ft_lstadd(&ps->ins, new);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int			ins_rev_rotate(t_ps *ps, char *in)
{
	t_list	*new;

	new = 0;
	if (in[0] == 'r' && in[1] == 'r')
	{
		if (in[2] == 'a' || in[2] == 'r')
			rev_rotate_stack(&ps->a);
		if (in[2] == 'b' || in[2] == 'r')
			rev_rotate_stack(&ps->b);
		if ((new = ft_lstnew(in, 4)))
			ft_lstadd(&ps->ins, new);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}
